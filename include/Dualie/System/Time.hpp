//
// Created by caleb on 8/1/24.
//

#ifndef DUALIE_TIME_HPP
#define DUALIE_TIME_HPP
#include <cstdint>
namespace dl
{
    /**
     * @brief A class that handles the conversion of time values.
     */
    class Time
    {
        uint64_t m_time;

    public:
        /**
         * @param val   The time value in milliseconds
         */
        explicit Time(uint64_t val);

        /**
         * @return The time value in microseconds
         */
        float asMicroseconds();

        /**
         * @return The time value in milliseconds
         */
        float asMilliseconds();

        /**
         * @return The time value in seconds
         */
        float asSeconds();

    };
}


#endif //DUALIE_TIME_HPP
