//
// Created by caleb on 8/1/24.
//

#include <Dualie/System/Clock.hpp>

dl::Clock::Clock()
{
    m_time = osGetTime();
}

dl::Time dl::Clock::restart()
{
    auto dt = osGetTime() - m_time;
    m_time = osGetTime();
    return dl::Time(dt);

}

dl::Time dl::Clock::getElapsedTime()
{
    return dl::Time(m_time);
}
