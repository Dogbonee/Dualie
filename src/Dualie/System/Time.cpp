//
// Created by caleb on 8/1/24.
//

#include <Dualie/System/Time.hpp>


dl::Time::Time(uint64_t val)
{
    m_time = val;
}

float dl::Time::asMicroseconds()
{
    return m_time * 1000.0f;
}

float dl::Time::asMilliseconds()
{
    return m_time;
}

float dl::Time::asSeconds()
{
    return m_time/1000.f;
}
