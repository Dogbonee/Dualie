//
// Created by caleb on 7/25/24.
//

#include <Dualie/Audio/Music.hpp>


dl::Music::Music(uint8_t channel) : m_opusFile(nullptr), m_quit(true), m_channel(channel)
{
    LightEvent_Init(&m_event, RESET_ONESHOT);
    allocateBuffers();

    ndspChnReset(channel);
    ndspChnSetInterp(channel, NDSP_INTERP_POLYPHASE);
    ndspChnSetRate(channel, Music::SAMPLE_RATE);
    ndspChnSetFormat(channel, NDSP_FORMAT_STEREO_PCM16);
}

dl::Music::~Music()
{
    stop();
    ndspChnReset(m_channel);
    linearFree(m_audioBuffer);
    op_free(m_opusFile);
}


bool dl::Music::loadFromFile(std::string path)
{
    if (m_opusFile)
    {
        op_free(m_opusFile);
        m_opusFile = nullptr;
    }

    int error;
    m_opusFile = op_open_file(path.c_str(), &error);
    if (error)
    {
        return false;
    }
    return true;
}

void dl::Music::play()
{
    if (!m_quit)
    {
        return;
    }

    m_quit = false;

    int32_t priority = 0x30;
    svcGetThreadPriority(&priority, CUR_THREAD_HANDLE);

    priority += 1;

    priority = priority < 0x18 ? 0x18 : priority;
    priority = priority > 0x3F ? 0x3F : priority;

    m_threadId = threadCreate(&Music::threadWrapper, this,
                              THREAD_STACK_SZ, priority,
                              THREAD_AFFINITY, false);
}

void dl::Music::restart()
{
    if (!m_quit)
    {
        stop();
    }
    reinitialize();
    play();
}

void dl::Music::stop()
{
    if(m_quit)
    {
        return;
    }
    m_quit = true;
    LightEvent_Signal(&m_event);

    // Free the audio thread
    threadJoin(m_threadId, UINT64_MAX);
    threadFree(m_threadId);
}

void dl::Music::audioThread()
{
    while (!m_quit)
    {
        for (size_t i = 0; i < std::size(m_waveBufs); ++i)
        {
            if (m_waveBufs[i].status != NDSP_WBUF_DONE)
            {
                continue;
            }

            if (!fillBuffer(&m_waveBufs[i]))
            {
                if (m_looping)
                {
                    reinitialize();
                    continue;
                }
                return;
            }
        }
        svcSleepThread(1000000);
    }
}
bool dl::Music::fillBuffer(ndspWaveBuf* waveBuf_)
{
    // Decode samples until our waveBuf is full
    int totalSamples = 0;
    while (totalSamples < SAMPLES_PER_BUF)
    {
        int16_t* buffer = waveBuf_->data_pcm16 + (totalSamples *
                                                  CHANNELS_PER_SAMPLE);
        const size_t bufferSize = (SAMPLES_PER_BUF - totalSamples) *
                                  CHANNELS_PER_SAMPLE;

        const int samples = op_read_stereo(m_opusFile, buffer, bufferSize);
        if (samples <= 0)
        {
            if (samples == 0)
            { break; }

            return false;
        }

        totalSamples += samples;
    }

    if (totalSamples == 0)
    {
        return false;
    }

    // Pass samples to NDSP
    waveBuf_->nsamples = totalSamples;
    ndspChnWaveBufAdd(m_channel, waveBuf_);
    DSP_FlushDataCache(waveBuf_->data_pcm16,
                       totalSamples * CHANNELS_PER_SAMPLE * sizeof(int16_t));

    return true;
}


void dl::Music::allocateBuffers()
{
    // Allocate audio buffer
    const size_t bufferSize = WAVEBUF_SIZE * std::size(m_waveBufs);
    m_audioBuffer = (int16_t*) linearAlloc(bufferSize);
    if (!m_audioBuffer)
    {
        exit(-1);
    }

    // Setup waveBufs for NDSP
    memset(&m_waveBufs, 0, sizeof(m_waveBufs));
    int16_t* buffer = m_audioBuffer;

    for (size_t i = 0; i < std::size(m_waveBufs); ++i)
    {
        m_waveBufs[i].data_vaddr = buffer;
        m_waveBufs[i].status = NDSP_WBUF_DONE;

        buffer += WAVEBUF_SIZE / sizeof(buffer[0]);
    }
}

void dl::Music::reinitialize()
{
    op_raw_seek(m_opusFile, 0);
    ndspChnWaveBufClear(m_channel);

    for (size_t i = 0; i < std::size(m_waveBufs); ++i)
    {
        m_waveBufs[i].status = NDSP_WBUF_DONE;
    }
}

void dl::Music::callbackWrapper(void* obj)
{
    dl::Music* music = static_cast<dl::Music*>(obj);

    if (!music->m_quit)
    {
        LightEvent_Signal(&music->m_event);
    }
}

void dl::Music::threadWrapper(void* obj)
{
    dl::Music* music = static_cast<dl::Music*>(obj);
    music->audioThread();
}

void dl::Music::setLooping(bool looping)
{
    m_looping = looping;
}





