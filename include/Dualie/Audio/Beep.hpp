//
// Created by caleb on 11/7/24.
//

#ifndef DUALIE_BEEP_HPP
#define DUALIE_BEEP_HPP

#include <3ds.h>
#include <cmath>
namespace dl
{
    /**
     * @brief A simple class that allows the generation of beeps at specific frequencies and durations
     */
    class Beep
    {

    private:
        static constexpr u32 SAMPLERATE = 22050;
        static constexpr u32 SAMPLESPERBUF = (SAMPLERATE/30);
        static constexpr u32 BYTESPERSAMPLE = 4;

        ndspWaveBuf m_waveBuf;
        u32* m_audioBuffer;
        int m_frequency;
        int m_channel;


        void fill_buffer(void* audioBuffer, size_t offset, size_t size, int frequency);

    public:
        /**
         * @param frequency frequency of the beep
         * @param duration_ms duration of the beep in milliseconds
         */
        explicit Beep(int frequency = 440, int duration_ms = 1000);
        ~Beep();

        /**
         * @brief plays the beep
         */
        void play();

        /**
         * @brief stops the beep
         */
        void stop();

        void setChannel(int channel);

    };

}
#endif //DUALIE_BEEP_HPP
