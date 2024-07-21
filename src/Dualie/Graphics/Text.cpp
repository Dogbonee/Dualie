//
// Created by caleb on 7/20/24.
//

#include <Dualie/Graphics/Text.hpp>

dl::Text::Text(const dl::TextBuffer &textBuffer) : m_scale(1.0f, 1.0f), m_alignment(AlignCenter)
{
    p_buf = textBuffer.m_buffer;
    m_defaultFont = C2D_FontLoadSystem(CFG_REGION_USA);

}


dl::Text::~Text()
{

    C2D_FontFree(m_defaultFont);
}

void dl::Text::draw(const dl::Vector2f &viewOffset) const
{
    C2D_DrawText(&m_textBuf, m_alignment, m_position.x - m_origin.x, m_position.y - m_origin.y, 0, m_scale.x, m_scale.y);
}


void dl::Text::setString(std::string str)
{
    m_textString = str;
    C2D_TextFontParse(&m_textBuf, m_defaultFont, p_buf, str.c_str());
    C2D_TextOptimize(&m_textBuf);
}

const std::string &dl::Text::getString()
{
    return m_textString;
}

void dl::Text::setOrigin(const dl::Vector2f &origin)
{
    m_origin = origin;
}

void dl::Text::setOrigin(float x, float y)
{
    m_origin = dl::Vector2f(x,y);
}


void dl::Text::setScale(const dl::Vector2f &scale)
{
    m_scale = scale;
}


float dl::Text::getWidth()
{
    return m_textBuf.width;
}


const dl::Vector2f &dl::Text::getOrigin()
{
    return m_origin;
}

const dl::Vector2f &dl::Text::getScale()
{
    return m_scale;
}

void dl::Text::updateDynamicText()
{
    setString(m_textString);
}

void dl::Text::setAlignment(dl::TextAlignment alignment)
{
    m_alignment = alignment;
}




