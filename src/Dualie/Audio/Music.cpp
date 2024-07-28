//
// Created by caleb on 7/25/24.
//

#include <Dualie/Audio/Music.hpp>



dl::Music::Music()
{
    LightEvent_Init(&m_event, RESET_ONESHOT);
    allocateBuffers();
}

dl::Music::~Music()
{
    ndspChnReset(0);
    linearFree(m_audioBuffer);
    op_free(m_opusFile);

}

std::string dl::Music::getOpusErrorString(int error)
{
    switch(error) {
        case OP_FALSE:
            return "OP_FALSE: A request did not succeed.";
        case OP_HOLE:
            return "OP_HOLE: There was a hole in the page sequence numbers.";
        case OP_EREAD:
            return "OP_EREAD: An underlying read, seek or tell operation "
                   "failed.";
        case OP_EFAULT:
            return "OP_EFAULT: A NULL pointer was passed where none was "
                   "expected, or an internal library error was encountered.";
        case OP_EIMPL:
            return "OP_EIMPL: The stream used a feature which is not "
                   "implemented.";
        case OP_EINVAL:
            return "OP_EINVAL: One or more parameters to a function were "
                   "invalid.";
        case OP_ENOTFORMAT:
            return "OP_ENOTFORMAT: This is not a valid Ogg Opus stream.";
        case OP_EBADHEADER:
            return "OP_EBADHEADER: A required header packet was not properly "
                   "formatted.";
        case OP_EVERSION:
            return "OP_EVERSION: The ID header contained an unrecognised "
                   "version number.";
        case OP_EBADPACKET:
            return "OP_EBADPACKET: An audio packet failed to decode properly.";
        case OP_EBADLINK:
            return "OP_EBADLINK: We failed to find data we had seen before or "
                   "the stream was sufficiently corrupt that seeking is "
                   "impossible.";
        case OP_ENOSEEK:
            return "OP_ENOSEEK: An operation that requires seeking was "
                   "requested on an unseekable stream.";
        case OP_EBADTIMESTAMP:
            return "OP_EBADTIMESTAMP: The first or last granule position of a "
                   "link failed basic validity checks.";
        default:
            return "Unknown error.";
    }
}



void dl::Music::loadFromFile(std::string path)
{
    int error;
    m_opusFile = op_open_file(path.c_str(), &error);
    if(error)
    {
        printf("Failed to open file: error %d (%s)\n", error,
               getOpusErrorString(error).c_str());
    }
}

void dl::Music::play()
{
    // Set the ndsp sound frame callback which signals our audioThread
    m_quit = false;
    ndspSetCallback(&dl::Music::callbackWrapper, this);

    // Spawn audio thread

    // Set the thread priority to the main thread's priority ...
    int32_t priority = 0x30;
    svcGetThreadPriority(&priority, CUR_THREAD_HANDLE);
    // ... then subtract 1, as lower number => higher actual priority ...
    priority -= 1;
    // ... finally, clamp it between 0x18 and 0x3F to guarantee that it's valid.
    priority = priority < 0x18 ? 0x18 : priority;
    priority = priority > 0x3F ? 0x3F : priority;

    // Start the thread, passing our opusFile as an argument.
    m_threadId = threadCreate(&Music::threadWrapper, this,
                                         THREAD_STACK_SZ, priority,
                                         THREAD_AFFINITY, false);
}

void dl::Music::restart()
{
    if(!m_quit)
    {
        stop();
    }
    op_raw_seek(m_opusFile, 0);
    ndspChnWaveBufClear(0);
    linearFree(m_audioBuffer);
    allocateBuffers();
    play();
}

void dl::Music::stop()
{
    m_quit = true;
    LightEvent_Signal(&m_event);

    // Free the audio thread
    threadJoin(m_threadId, UINT64_MAX);
    threadFree(m_threadId);

}

void dl::Music::audioCallback(void* const nul_)
{
    (void)nul_;  // Unused

    if(m_quit) { // Quit flag
        return;
    }

    LightEvent_Signal(&m_event);

}

void dl::Music::audioThread()
{


    while(!m_quit) {  // Whilst the quit flag is unset,
        // search our waveBufs and fill any that aren't currently
        // queued for playback (i.e, those that are 'done')
        for(size_t i = 0; i < ARRAY_SIZE(m_waveBufs); ++i) {
            if(m_waveBufs[i].status != NDSP_WBUF_DONE) {
                continue;
            }

            if(!fillBuffer(&m_waveBufs[i])) {   // Playback complete
                if(m_looping){
                    op_raw_seek(m_opusFile, 0);
                    ndspChnWaveBufClear(0);
                    linearFree(m_audioBuffer);
                    allocateBuffers();
                    continue;
                }
                return;
            }
        }

        // Wait for a signal that we're needed again before continuing,
        // so that we can yield to other things that want to run
        // (Note that the 3DS uses cooperative threading)
        LightEvent_Wait(&m_event);
    }
}

bool dl::Music::fillBuffer(ndspWaveBuf* waveBuf_)
{
    // Decode samples until our waveBuf is full
    int totalSamples = 0;
    while(totalSamples < SAMPLES_PER_BUF) {
        int16_t *buffer = waveBuf_->data_pcm16 + (totalSamples *
                                                  CHANNELS_PER_SAMPLE);
        const size_t bufferSize = (SAMPLES_PER_BUF - totalSamples) *
                                  CHANNELS_PER_SAMPLE;

        // Decode bufferSize samples from opusFile_ into buffer,
        // storing the number of samples that were decoded (or error)
        const int samples = op_read_stereo(m_opusFile, buffer, bufferSize);
        if(samples <= 0) {
            if(samples == 0) break;  // No error here

            printf("op_read_stereo: error %d (%s)", samples,
                    getOpusErrorString(samples).c_str());
            break;
        }

        totalSamples += samples;
    }

    // If no samples were read in the last decode cycle, we're done
    if(totalSamples == 0) {
        return false;
    }

    // Pass samples to NDSP
    waveBuf_->nsamples = totalSamples;
    ndspChnWaveBufAdd(0, waveBuf_);
    DSP_FlushDataCache(waveBuf_->data_pcm16,
                       totalSamples * CHANNELS_PER_SAMPLE * sizeof(int16_t));

    return true;
}

void dl::Music::callbackWrapper(void* obj)
{
    dl::Music* music = static_cast<dl::Music*>(obj);
    music->audioCallback(nullptr);
}

void dl::Music::threadWrapper(void* obj)
{
    dl::Music* music = static_cast<dl::Music*>(obj);
    music->audioThread();
}

void dl::Music::allocateBuffers()
{
    // Allocate audio buffer
    const size_t bufferSize = WAVEBUF_SIZE * ARRAY_SIZE(m_waveBufs);
    m_audioBuffer = (int16_t *)linearAlloc(bufferSize);
    if(!m_audioBuffer) {
        exit(-1);
    }

    // Setup waveBufs for NDSP
    memset(&m_waveBufs, 0, sizeof(m_waveBufs));
    int16_t *buffer = m_audioBuffer;

    for(size_t i = 0; i < ARRAY_SIZE(m_waveBufs); ++i) {
        m_waveBufs[i].data_vaddr = buffer;
        m_waveBufs[i].status     = NDSP_WBUF_DONE;

        buffer += WAVEBUF_SIZE / sizeof(buffer[0]);
    }
}

void dl::Music::setLooping(bool looping)
{
    m_looping = looping;
}




