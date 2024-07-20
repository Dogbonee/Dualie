//
// Created by caleb on 6/16/24.
//

#include <Dualie/Graphics/CircleShape.hpp>

dl::CircleShape::CircleShape() : m_radius(0){

}

dl::CircleShape::CircleShape(float radius) : m_radius(radius) {
    m_size = dl::Vector2f(radius*2, radius*2);
}

void dl::CircleShape::setRadius(float radius) {
    m_radius = radius;
    m_size = dl::Vector2f(radius*2, radius*2);
}

void dl::CircleShape::draw(const dl::Vector2f& viewOffset) const {
    C2D_DrawCircle(m_position.x - m_origin.x - viewOffset.x, m_position.y - m_origin.y - viewOffset.y, 0, m_radius, m_color.getColorValue(), m_color.getColorValue(), m_color.getColorValue(), m_color.getColorValue());
}
