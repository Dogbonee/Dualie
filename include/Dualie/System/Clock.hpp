//
// Created by caleb on 8/1/24.
//

#ifndef DUALIE_CLOCK_HPP
#define DUALIE_CLOCK_HPP

#include <3ds.h>
#include <Dualie/System/Time.hpp>
namespace dl
{
    /**
     * @brief A class that handles the passing of time within the program
     */
    class Clock
    {

        uint64_t m_time;

    public:
        Clock();

        /**
         * @brief Restarts the clock and returns its elapsed time value
         * @return The clock's last time value
         */
        dl::Time restart();

        /**
         * @return The elapsed time of the clock since its last restart or creation
         */
        dl::Time getElapsedTime();
    };
}


#endif //DUALIE_CLOCK_HPP
