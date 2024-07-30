//
// Created by caleb on 6/16/24.
//

#ifndef DUALIE_TRANSFORMABLE_HPP
#define DUALIE_TRANSFORMABLE_HPP


#include <Dualie/System/Vector2.hpp>

namespace dl {

    /**
     * @brief A base class for anything that has a position on the screen
     */
    class Transformable {

    protected:
        dl::Vector2f m_position;


    public:
        /**
         * @brief Sets the position of the transformable
         * @param position  The position to set
         */
        virtual void setPosition(const dl::Vector2f& position);

        /**
         * @brief Sets the position of the transformable
         * @param x  The position to set (X)
         * @param y  The position to set (Y)
         */
        void setPosition(float x, float y);

        /**
         * @brief Moves the transformable offset number of pixels.
         * @param offset    The offset to move
         */
        virtual void move(const dl::Vector2f& offset);

        /**
         * @brief Moves the transformable offset number of pixels.
         * @param xOffset   The offset to move (X)
         * @param yOffset   The offset to move (Y)
         */
        void move(float xOffset, float yOffset);

        /**
         * @return The transformable's position
         */
        const dl::Vector2f& getPosition() const;

    };

}


#endif //DUALIE_TRANSFORMABLE_HPP
