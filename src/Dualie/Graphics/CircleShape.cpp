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

void dl::CircleShape::draw(const dl::Vector2f& viewOffset) {
    auto vo = m_bViewDoesAffect ? viewOffset : dl::Vector2f(0,0);
    if(m_outlineThickness > 0){
        C2D_DrawCircle(m_position.x + m_radius - m_origin.x - vo.x, m_position.y + m_radius - m_origin.y - vo.y, 0, m_radius, m_outlineColor.getColorValue(), m_outlineColor.getColorValue(), m_outlineColor.getColorValue(), m_outlineColor.getColorValue());
    }
    C2D_DrawCircle(m_position.x + m_radius - m_origin.x - vo.x, m_position.y + m_radius - m_origin.y - vo.y, 0, m_radius - m_outlineThickness, m_fillColor.getColorValue(), m_fillColor.getColorValue(), m_fillColor.getColorValue(), m_fillColor.getColorValue());
}
