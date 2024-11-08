//
// Created by caleb on 11/7/24.
//

#ifndef DUALIE_BEEP_HPP
#define DUALIE_BEEP_HPP

#include <3ds.h>
#include <cmath>

class Beep
{

private:

    static constexpr u32 SAMPLERATE = 22050;
    static constexpr u32 SAMPLESPERBUF = (SAMPLERATE / 30);
    static constexpr u32 BYTESPERSAMPLE = 4;
    ndspWaveBuf m_waveBuf;
    u32* m_audioBuffer;
    int m_frequency;
    void fill_buffer(void* audioBuffer, size_t offset, size_t size, int frequency);


public:
    explicit Beep(int frequency);

    void play();
};


#endif //DUALIE_BEEP_HPP
