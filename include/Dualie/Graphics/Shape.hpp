//
// Created by caleb on 6/16/24.
//

#ifndef DUALIE_SHAPE_HPP
#define DUALIE_SHAPE_HPP


#include <Dualie/Graphics/Color.hpp>
#include <Dualie/Graphics/Transformable.hpp>
#include <Dualie/Graphics/Drawable.hpp>
#include <Dualie/System/Rect.hpp>

namespace dl {

    /**
     * @brief The base class for any shape
     */
    class Shape : public dl::Transformable, public dl::Drawable {

    protected:
        dl::Color m_fillColor;
        dl::Color m_outlineColor;
        float m_outlineThickness;
        dl::Vector2f m_origin;
        dl::Vector2f m_size;

    public:
        Shape();

        /**
         * @brief Sets the fill color of the shape
         * @param color     The color to fill with
         */
        void setFillColor(const dl::Color& color);

        /**
         * @brief Sets the outline color of the shape
         * @param color     The color to outline with
         */
        void setOutlineColor(const dl::Color& color);

        /**
         * @brief Sets the outline thickness of the shape
         * @param thickness    The outline thickness in pixels
         */
        void setOutlineThickness(float thickness);

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
         * @return The size in pixels
         */
        const dl::Vector2f& getSize();

        /**
         * @return The origin in pixels
         */
        const dl::Vector2f& getOrigin();

        /**
         * @return The local bounds (Not affected by position) of the shape in pixels as a FloatRect
         */
        dl::FloatRect getLocalBounds();

        /**
         * @return The global bounds (Affected by position) of the shape in pixels as a FloatRect
         */
        dl::FloatRect getGlobalBounds();

        /**
         * @return The fill color of the shape
         */
        const Color &getFillColor() const;

        /**
         * @return The outline color of the shape
         */
        const Color &getOutlineColor() const;

        /**
         * @return The outline thickness of the shape
         */
        const float& getOutlineThickness();

    };
}


#endif //DUALIE_SHAPE_HPP
