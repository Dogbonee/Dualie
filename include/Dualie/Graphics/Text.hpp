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

    enum TextAlignment
    {
        AtBaseline       = BIT(0), ///< Matches the Y coordinate with the baseline of the font.
        WithColor        = BIT(1), ///< Draws text with color. Requires a u32 color value.
        AlignLeft        = 0 << 2, ///< Draws text aligned to the left. This is the default.
        AlignRight       = 1 << 2, ///< Draws text aligned to the right.
        AlignCenter      = 2 << 2, ///< Draws text centered.
        AlignJustified   = 3 << 2, ///< Draws text justified. When C2D_WordWrap is not specified, right edge is x + scaleX*text->width. Otherwise, right edge is x + the width specified for those values.
        AlignMask        = 3 << 2, ///< Bitmask for alignment values.
        WordWrap         = BIT(4), ///< Draws text with wrapping of full words before specified width. Requires a float value, passed after color if C2D_WithColor is specified.
    };

class Text : public dl::Transformable, public dl::Drawable
    {
        C2D_TextBuf p_buf;
        C2D_Text m_textBuf;
        C2D_Font m_defaultFont;
        C2D_Font m_customFont;
        TextAlignment m_alignment;

        std::string m_textString;

        dl::Vector2f m_origin;

        dl::Vector2f m_scale;

    public:
        explicit Text(const dl::TextBuffer& textBuffer);
        ~Text();

        void updateDynamicText();

        void setString(std::string str);
        void setScale(const dl::Vector2f& scale);
        void setAlignment(TextAlignment alignment);

        void setOrigin(const dl::Vector2f& origin);
        void setOrigin(float x, float y);

        const std::string &getString();
        float getWidth();
        const dl::Vector2f& getOrigin();
        const dl::Vector2f& getScale();

        void draw(const dl::Vector2f &viewOffset) override;


    };

}

#endif //DUALIE_TEXT_HPP
