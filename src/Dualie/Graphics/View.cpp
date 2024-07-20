//
// Created by caleb on 6/18/24.
//

#include <Dualie/Graphics/View.hpp>

dl::View::View() = default;

dl::View::View(const dl::FloatRect &viewRect) {
    m_viewRect = viewRect;
}

void dl::View::reset(const dl::FloatRect &viewRect) {
    m_viewRect = viewRect;
}

void dl::View::setCenter(dl::Vector2f center) {
    m_viewRect.left = center.x - m_viewRect.width/2.0f;
    m_viewRect.top = center.y - m_viewRect.height/2.0f;
}

void dl::View::move(dl::Vector2f offset) {
    m_viewRect.left += offset.x;
    m_viewRect.top += offset.y;
}

dl::Vector2f dl::View::getOffset() {
    return {m_viewRect.left, m_viewRect.top};
}
