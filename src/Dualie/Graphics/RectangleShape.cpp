//
// Created by caleb on 6/17/24.
//

#include <Dualie/Graphics/RectangleShape.hpp>

dl::RectangleShape::RectangleShape() {

}

dl::RectangleShape::RectangleShape(const dl::Vector2f &size) {
    m_size = size;
}

void dl::RectangleShape::setSize(const dl::Vector2f &size) {
    m_size = size;
}

void dl::RectangleShape::draw(const dl::Vector2f& viewOffset)  {
    auto vo = m_bViewDoesAffect ? viewOffset : dl::Vector2f(0,0);
    if(m_outlineThickness > 0){
        C2D_DrawRectSolid(m_position.x - m_origin.x - vo.x, m_position.y - m_origin.y - vo.y, 0, m_size.x, m_size.y, m_outlineColor.getColorValue());
    }
    C2D_DrawRectSolid(m_position.x + m_outlineThickness - m_origin.x - vo.x, m_position.y + m_outlineThickness - m_origin.y - vo.y, 0, m_size.x - m_outlineThickness * 2.f, m_size.y - m_outlineThickness * 2.f, m_fillColor.getColorValue());
}
