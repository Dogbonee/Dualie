//
// Created by caleb on 6/16/24.
//

#include <Dualie/Graphics/Transformable.hpp>


void dl::Transformable::setPosition(const dl::Vector2f& position) {
    m_position = position;
}

void dl::Transformable::setPosition(float x, float y) {
    setPosition(dl::Vector2f(x,y));
}

const dl::Vector2f &dl::Transformable::getPosition() const{
    return m_position;
}

void dl::Transformable::move(const dl::Vector2f &offset) {
    m_position.x += offset.x;
    m_position.y += offset.y;
}

void dl::Transformable::move(float xOffset, float yOffset) {
    move(dl::Vector2f(xOffset,yOffset));
}
