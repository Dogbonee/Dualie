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
    /**
    * @brief A simple class responsible for the line object
    */
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

        /**
        * @brief Sets the starting position of the line.
        * @param startingPosition     The starting position of the line
        */
        void setStartingPosition(const dl::Vector2f& startingPosition);

        /**
        * @brief Sets the ending position of the line.
        * @param startingPosition     The ending position of the line
        */
        void setEndingPosition(const dl::Vector2f& endingPosition);

        /**
        * @brief Sets the thickness of the line.
        * @param thickness     The thickness of the line
        */
        void setThickness(float thickness);

        /**
        * @brief Sets the color of the line.
        * @param thickness     The color of the line
        */
        void setColor(const dl::Color& color);

        /**
        * @return The starting position of the line
        */
        const dl::Vector2f& getStartingPosition();

        /**
        * @return The ending position of the line
        */
        const dl::Vector2f& getEndingPosition();

        /**
        * @return The thickness of the line
        */
        float getThickness();

        /**
        * @return The color of the line
        */
        const dl::Color& getColor();

    };

}


#endif //DUALIE_LINE_HPP
