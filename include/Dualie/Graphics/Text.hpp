//
// Created by caleb on 7/20/24.
//

#ifndef DUALIE_TEXT_HPP
#define DUALIE_TEXT_HPP
#include <citro2d.h>
#include <Dualie/Graphics/Transformable.hpp>
#include <Dualie/Graphics/Drawable.hpp>



namespace dl
{
class Text : public dl::Transformable, public dl::Drawable
    {
        C2D_TextBuf m_staticBuf;
        C2D_Text m_textBuf;
        C2D_Font m_defaultFont;
        C2D_Font m_customFont;

        std::string m_textString;

    public:
        Text();
        ~Text();

        void setString(std::string str);
        const std::string &getString();

        float getWidth();

        void draw(const dl::Vector2f &viewOffset) const override;


    };

}

#endif //DUALIE_TEXT_HPP
