//
// Created by caleb on 7/20/24.
//

#ifndef DUALIE_TEXT_HPP
#define DUALIE_TEXT_HPP
#include <citro2d.h>
#include <Dualie/Graphics/Transformable.hpp>
#include <Dualie/Graphics/Drawable.hpp>
#include <Dualie/Graphics/TextBuffer.hpp>



namespace dl
{
class Text : public dl::Transformable, public dl::Drawable
    {
        C2D_TextBuf p_buf;
        C2D_Text m_textBuf;
        C2D_Font m_defaultFont;
        C2D_Font m_customFont;

        std::string m_textString;

        dl::Vector2f m_origin;

        dl::Vector2f m_scale;

    public:
        explicit Text(const dl::TextBuffer& textBuffer);
        ~Text();

        void setString(std::string str);
        void setScale(const dl::Vector2f& scale);


        void setOrigin(const dl::Vector2f& origin);
        void setOrigin(float x, float y);

        const std::string &getString();
        float getWidth();
        const dl::Vector2f& getOrigin();
        const dl::Vector2f& getScale();

        void draw(const dl::Vector2f &viewOffset) const override;


    };

}

#endif //DUALIE_TEXT_HPP
