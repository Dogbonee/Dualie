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
        dl::Color m_color;
        dl::Vector2f m_origin;
        dl::Vector2f m_size;

    public:
        void setFillColor(const dl::Color& color);
        void setOrigin(const dl::Vector2f& origin);

        virtual const dl::Vector2f& getSize();
        virtual dl::FloatRect getLocalBounds();
        virtual dl::FloatRect getGlobalBounds();






    };
}


#endif //DUALIE_SHAPE_HPP
