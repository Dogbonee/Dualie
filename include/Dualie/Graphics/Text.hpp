//
// Created by caleb on 7/20/24.
//

#ifndef DUALIE_TEXT_HPP
#define DUALIE_TEXT_HPP
#include <citro2d.h>
#include <Dualie/Graphics/Transformable.hpp>
#include <Dualie/Graphics/Drawable.hpp>
#include <Dualie/Graphics/TextBuffer.hpp>
#include <Dualie/Graphics/Color.hpp>


namespace dl
{

    enum TextAlignment
    {
        AtBaseline       = BIT(0), ///< Matches the Y coordinate with the baseline of the font.
        AlignLeft        = 0 << 2, ///< Draws text aligned to the left. This is the default.
        AlignRight       = 1 << 2, ///< Draws text aligned to the right.
        AlignCenter      = 2 << 2, ///< Draws text centered.
        AlignJustified   = 3 << 2, ///< Draws text justified. When C2D_WordWrap is not specified, right edge is x + scaleX*text->width. Otherwise, right edge is x + the width specified for those values.
        AlignMask        = 3 << 2, ///< Bitmask for alignment values.
    };

    /**
     * @brief A class used to handle the transformation and drawing of visible text
     */
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
            dl::Color m_color;

        public:
            explicit Text(const dl::TextBuffer& textBuffer);
            ~Text();

            /**
             * @brief reparses and reoptimizes the text. This should be used if you call TextBuffer::flushBuffer beforehand.
             */
            void updateDynamicText();

            /**
             * @brief Sets the text's string
             * @param str   The string to set
             */
            void setString(std::string str);

            /**
             * @brief Sets the scale of the text
             * @param scale     The scale to set
             */
            void setScale(const dl::Vector2f& scale);

            /**
            * @brief Sets the alignment of the text
            * @param scale     The alignment to set
            */
            void setAlignment(TextAlignment alignment);

            /**
            * @brief Sets the origin of the shape. The default origin is (0,0) and is the top left pixel of the shape bounds.
            * Setting the origin can affect where the shape is drawn. For instance, setting the origin to be half the shape size
            * will cause the shape to be centered on its position.
            * @param origin    The origin in pixels
            */
            void setOrigin(const dl::Vector2f& origin);

            /**
            * @brief Sets the origin of the shape. The default origin is (0,0) and is the top left pixel of the shape bounds.
            * Setting the origin can affect where the shape is drawn. For instance, setting the origin to be half the shape size
            * will cause the shape to be centered on its position.
            * @param x    The origin in pixels (X)
            * @param y    The origin in pixels (Y)
            */
            void setOrigin(float x, float y);

            /**
             * @brief Sets the color of the text
             * @param color     The color to set;
             */
            void setColor(const dl::Color& color);

            /**
             *
             * @return The text's string
             */
            const std::string &getString();


            /**
             * @return the origin in pixels
             */
            const dl::Vector2f& getOrigin();

            /**
             *
             * @return the scale in pixels
             */
            const dl::Vector2f& getScale();

            void draw(const dl::Vector2f &viewOffset) override;


        };

}

#endif //DUALIE_TEXT_HPP
