//
// Created by caleb on 6/16/24.
//

#include <Dualie/Graphics/Shape.hpp>

dl::Shape::Shape() : m_outlineThickness(0)
{}

void dl::Shape::setFillColor(const dl::Color &color) {
    m_fillColor = color;
}

void dl::Shape::setOrigin(const dl::Vector2f &origin) {
    m_origin = origin;
}

void dl::Shape::setOrigin(float x, float y)
{
    m_origin = dl::Vector2f(x,y);
}

dl::FloatRect dl::Shape::getLocalBounds() {
    return {dl::Vector2f(0,0) - m_origin, m_size};
}

dl::FloatRect dl::Shape::getGlobalBounds() {
    return {m_position - m_origin, m_size};
}

void dl::Shape::setOutlineColor(const dl::Color &color)
{
    m_outlineColor = color;
}

void dl::Shape::setOutlineThickness(float thickness)
{
    m_outlineThickness = thickness;
}


const dl::Vector2f &dl::Shape::getSize() {
    return m_size;
}

const dl::Color &dl::Shape::getFillColor() const
{
    return m_fillColor;
}

const dl::Color &dl::Shape::getOutlineColor() const
{
    return m_outlineColor;
}


const float &dl::Shape::getOutlineThickness()
{
    return m_outlineThickness;
}



const dl::Vector2f &dl::Shape::getOrigin()
{
    return m_origin;
}




