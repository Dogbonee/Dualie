//
// Created by caleb on 6/16/24.
//

#include <Dualie/Graphics/Color.hpp>

dl::Color::Color(){
    m_color = C2D_Color32(255,255,255, 255);
}

dl::Color::Color(std::uint8_t red, std::uint8_t green, std::uint8_t blue, std::uint8_t alpha) {

    m_color = C2D_Color32(red, green,blue,alpha);
}

dl::Color::Color(std::uint32_t color) {

    m_color = color;
}

const u32 & dl::Color::getColorValue() const {
    return m_color;
}

inline dl::Color dl::Color::Black(0, 0, 0);
inline dl::Color dl::Color::White(255, 255, 255);
inline dl::Color dl::Color::Red(255, 0, 0);
inline dl::Color dl::Color::Green(0, 255, 0);
inline dl::Color dl::Color::Blue(0, 0, 255);
inline dl::Color dl::Color::Yellow(255, 255, 0);
inline dl::Color dl::Color::Magenta(255, 0, 255);
inline dl::Color dl::Color::Cyan(0, 255, 255);
inline dl::Color dl::Color::Transparent(0, 0, 0, 0);