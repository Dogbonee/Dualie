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

void dl::RectangleShape::draw(const dl::Vector2f& viewOffset) const {
    C2D_DrawRectSolid(m_position.x - m_origin.x - viewOffset.x, m_position.y - m_origin.y - viewOffset.y, 0, m_size.x, m_size.y, m_color.getColorValue());
}
