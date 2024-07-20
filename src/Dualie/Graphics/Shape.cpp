//
// Created by caleb on 6/16/24.
//

#include <Dualie/Graphics/Shape.hpp>


void dl::Shape::setFillColor(const dl::Color &color) {
    m_color = color;
}

void dl::Shape::setOrigin(const dl::Vector2f &origin) {
    m_origin = origin;
}

dl::FloatRect dl::Shape::getLocalBounds() {
    return {dl::Vector2f(0,0) - m_origin, m_size};
}

dl::FloatRect dl::Shape::getGlobalBounds() {
    return {m_position - m_origin, m_size};
}

const dl::Vector2f &dl::Shape::getSize() {
    return m_size;
}


