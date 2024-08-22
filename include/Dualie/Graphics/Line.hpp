//
// Created by caleb on 8/21/24.
//

#ifndef DUALIE_LINE_HPP
#define DUALIE_LINE_HPP

#include <citro2d.h>
#include <Dualie/Graphics/Drawable.hpp>
#include <Dualie/Graphics/Color.hpp>

namespace dl
{
    class Line : public dl::Drawable
    {
        dl::Vector2f m_startingPosition;
        dl::Vector2f m_endingPosition;
        float m_thickness;
        dl::Color m_color;

    public:
        Line();
        Line(dl::Vector2f startingPosition, dl::Vector2f endingPosition, float thickness = 1);
        void draw(const Vector2f &viewOffset) override;

        void setStartingPosition(const dl::Vector2f& startingPosition);
        void setEndingPosition(const dl::Vector2f& endingPosition);
        void setThickness(float thickness);
        void setColor(const dl::Color& color);

        const dl::Vector2f& getStartingPosition();
        const dl::Vector2f& getEndingPosition();
        float getThickness();
        const dl::Color& getColor();

    };

}


#endif //DUALIE_LINE_HPP
