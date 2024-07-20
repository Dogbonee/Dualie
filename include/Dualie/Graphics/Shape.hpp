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
    class Shape : public dl::Transformable, public dl::Drawable {

    protected:
        dl::Color m_fillColor;
        dl::Color m_outlineColor;
        float m_outlineThickness;
        dl::Vector2f m_origin;
        dl::Vector2f m_size;

    public:
        Shape();
        void setFillColor(const dl::Color& color);
        void setOutlineColor(const dl::Color& color);
        void setOutlineThickness(float thickness);
        void setOrigin(const dl::Vector2f& origin);

        const dl::Vector2f& getSize();
        dl::FloatRect getLocalBounds();
        dl::FloatRect getGlobalBounds();
        const Color &getFillColor() const;
        const Color &getOutlineColor() const;
        const float& getOutlineThickness();






    };
}


#endif //DUALIE_SHAPE_HPP
