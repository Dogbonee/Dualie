//
// Created by caleb on 7/20/24.
//

#include <Dualie/Graphics/Text.hpp>

dl::Text::Text()
{
    m_staticBuf = C2D_TextBufNew(4096);
    m_defaultFont = C2D_FontLoadSystem(CFG_REGION_USA);

}


dl::Text::~Text()
{
    C2D_TextBufDelete(m_staticBuf);
    C2D_FontFree(m_defaultFont);
}

void dl::Text::draw(const dl::Vector2f &viewOffset) const
{
    C2D_DrawText(&m_textBuf, 0, m_position.x - m_origin.x, m_position.y - m_origin.y, 0, 1,1);
}


void dl::Text::setString(std::string str)
{
    m_textString = str;
    C2D_TextFontParse(&m_textBuf, m_defaultFont, m_staticBuf, str.c_str());
    C2D_TextOptimize(&m_textBuf);
}

const std::string &dl::Text::getString()
{
    return m_textString;
}

float dl::Text::getWidth()
{
    return m_textBuf.width;
}

void dl::Text::setOrigin(const dl::Vector2f &origin)
{
    m_origin = origin;
}

void dl::Text::setOrigin(float x, float y)
{
    m_origin = dl::Vector2f(x,y);
}

const dl::Vector2f &dl::Text::getOrigin()
{
    return m_origin;
}


