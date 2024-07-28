//
// Created by caleb on 7/25/24.
//

#ifndef DUALIE_MUSIC_HPP
#define DUALIE_MUSIC_HPP
#include <iostream>
#include <cstring>
#include <opusfile.h>
#include <3ds.h>
#include <functional>
#include <thread>


#define ARRAY_SIZE(x) (sizeof(x) / sizeof((x)[0]))

namespace dl
{

    class Music
    {

        static constexpr int SAMPLE_RATE = 48000;            // Opus is fixed at 48kHz
        static constexpr int SAMPLES_PER_BUF = SAMPLE_RATE * 120 / 1000;  // 120ms buffer
        static constexpr int CHANNELS_PER_SAMPLE = 2;

        static constexpr int THREAD_AFFINITY = -1;           // Execute thread on any core
        static constexpr int THREAD_STACK_SZ = 32 * 1024;    // 32kB stack for audio thread

        static constexpr size_t WAVEBUF_SIZE = SAMPLES_PER_BUF * CHANNELS_PER_SAMPLE * sizeof(int16_t);

        ndspWaveBuf s_waveBufs[3];
        int16_t* s_audioBuffer = nullptr;

        OggOpusFile* m_opusFile;

        LightEvent s_event;
        Thread m_threadId;
        volatile bool s_quit = false;  // Quit flag

        // Retrieve strings for libopusfile errors
        // Sourced from David Gow's example code: https://davidgow.net/files/opusal.cpp
        std::string getOpusErrorString(int error);
        void audioCallback(void* const nul_);
        static void callbackWrapper(void* obj);
        void audioThread();
        static void threadWrapper(void* obj);
        bool fillBuffer(ndspWaveBuf* waveBuf_);

    public:
        Music();
        ~Music();
        void loadFromFile(std::string path);

        void start();
        void stop();

    };

}
#endif //DUALIE_MUSIC_HPP
