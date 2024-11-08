//
// Created by caleb on 11/7/24.
//

#include <Dualie/Audio/Beep.hpp>
#include <cstring>



Beep::Beep(int frequency)
{
    m_audioBuffer = (u32*) linearAlloc(SAMPLESPERBUF * BYTESPERSAMPLE * 2);
    m_waveBuf.data_vaddr = &m_audioBuffer[0];
    m_waveBuf.nsamples = SAMPLESPERBUF;
    fill_buffer(m_audioBuffer,0, SAMPLESPERBUF * 2, m_frequency);
}


void Beep::fill_buffer(void* audioBuffer, size_t offset, size_t size, int frequency)
{
    u32* dest = (u32*) audioBuffer;

    for (int i = 0; i < size; i++) {
        // This is a simple sine wave, with a frequency of `frequency` Hz, and an amplitude 30% of maximum.
        s16 sample = 0.3 * 0x7FFF * sin(frequency * (2 * M_PI) * (offset + i) / SAMPLERATE);

        // Stereo samples are interleaved: left and right channels.
        dest[i] = (sample << 16) | (sample & 0xffff);
    }

    DSP_FlushDataCache(audioBuffer, size);
}

void Beep::play()
{
    ndspChnWaveBufAdd(0, &m_waveBuf);

}
