//
// Created by caleb on 11/7/24.
//

#include <Dualie/Audio/Beep.hpp>
#include <cstring>



dl::Beep::Beep(int frequency, int duration_ms) : m_frequency(frequency), m_channel(1)
{
    int num_samples = (duration_ms * SAMPLERATE) / 1000;
    m_audioBuffer = (u32*) linearAlloc(num_samples * BYTESPERSAMPLE);
    m_waveBuf.data_vaddr = &m_audioBuffer[0];
    m_waveBuf.nsamples = num_samples;
    fill_buffer(m_audioBuffer,0, num_samples, m_frequency);

    ndspSetOutputMode(NDSP_OUTPUT_STEREO);

    ndspChnSetInterp(0, NDSP_INTERP_LINEAR);
    ndspChnSetRate(0, SAMPLERATE);
    ndspChnSetFormat(0, NDSP_FORMAT_STEREO_PCM16);

}

dl::Beep::~Beep()
{
    linearFree(m_audioBuffer);
}



void dl::Beep::fill_buffer(void* audioBuffer, size_t offset, size_t size, int frequency)
{
    u32* dest = (u32*) audioBuffer;

    for (size_t i = 0; i < size; i++) {
        // This is a simple sine wave, with a frequency of `frequency` Hz, and an amplitude 30% of maximum.
        s16 sample = 0.3 * 0x7FFF * sin(frequency * (2 * M_PI) * (offset + i) / SAMPLERATE);

        // Stereo samples are interleaved: left and right channels.
        dest[i] = (sample << 16) | (sample & 0xffff);
    }

    DSP_FlushDataCache(audioBuffer, size);
}

void dl::Beep::play()
{
    ndspChnWaveBufAdd(m_channel, &m_waveBuf);
}

void dl::Beep::stop()
{
    ndspChnReset(m_channel);
}

void dl::Beep::setChannel(int channel)
{
    m_channel = channel;
}





