//
// Created by caleb on 8/21/24.
//

#include <Dualie/Graphics/Line.hpp>

dl::Line::Line() : m_thickness(1), m_color(dl::Color::White)
{

}

dl::Line::Line(dl::Vector2f startingPosition, dl::Vector2f endingPosition, float thickness) : m_startingPosition(startingPosition), m_endingPosition(endingPosition), m_thickness(thickness), m_color(dl::Color::White)
{

}

void dl::Line::draw(const dl::Vector2f &viewOffset)
{
    C2D_DrawLine(m_startingPosition.x - viewOffset.x, m_startingPosition.y - viewOffset.y, m_color.getColorValue(), m_endingPosition.x - viewOffset.x, m_endingPosition.y - viewOffset.y, m_color.getColorValue(), m_thickness, 0);
}

void dl::Line::setStartingPosition(const dl::Vector2f &startingPosition)
{
    m_startingPosition = startingPosition;
}

void dl::Line::setEndingPosition(const dl::Vector2f &endingPosition)
{
    m_endingPosition = endingPosition;
}

void dl::Line::setThickness(float thickness)
{
    m_thickness = thickness;
}

void dl::Line::setColor(const dl::Color &color)
{
    m_color = color;
}

const dl::Vector2f &dl::Line::getStartingPosition()
{
    return m_startingPosition;
}

const dl::Vector2f &dl::Line::getEndingPosition()
{
    return m_endingPosition;
}

float dl::Line::getThickness()
{
    return m_thickness;
}

const dl::Color &dl::Line::getColor()
{
    return m_color;
}


