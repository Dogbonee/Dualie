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



namespace dl
{

    /**
     * @brief A class that handles the playback of opus audio files
     */
    class Music
    {
        uint8_t m_channel;
        ndspWaveBuf m_waveBufs[3];
        int16_t* m_audioBuffer = nullptr;

        OggOpusFile* m_opusFile;

        LightEvent m_event;
        Thread m_threadId;

        volatile bool m_quit = false;
        bool m_looping = false;

        bool fillBuffer(ndspWaveBuf* waveBuf_);
        void allocateBuffers();
        void reinitialize();
        void audioThread();
        static void callbackWrapper(void* obj);
        static void threadWrapper(void* obj);

    public:
        explicit Music(uint8_t channel);
        ~Music();

        /**
         * @brief loads a opus file from romfs
         * @param path  The path of the file to open
         * @returns True if the load succeeded, false otherwise.
         */
        bool loadFromFile(std::string path);

        /**
         * @brief Plays the opus music file loaded
         */
        void play();

        /**
         * @brief Restarts the song from the beginning. If playback is stopped, it plays it
         */
        void restart();

        /**
         * @brief Stops the currently playing song. Maintains the current position of the music.
         */
        void stop();

        /**
         * @brief Sets whether the music should loop when finished
         * @param looping   Music should loop or not
         */
        void setLooping(bool looping);

        static constexpr int SAMPLE_RATE = 48000; // Opus is fixed at 48kHz
        static constexpr int SAMPLES_PER_BUF = SAMPLE_RATE * 120 / 1000;  // 120ms buffer
        static constexpr int CHANNELS_PER_SAMPLE = 2;
        static constexpr int THREAD_AFFINITY = -1;           // No thread affinity
        static constexpr int THREAD_STACK_SZ = 32 * 1024;    // 32kB stack for audio thread
        static constexpr size_t WAVEBUF_SIZE = SAMPLES_PER_BUF * CHANNELS_PER_SAMPLE * sizeof(int16_t);
    };

}
#endif //DUALIE_MUSIC_HPP
