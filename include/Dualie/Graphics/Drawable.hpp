//
// Created by caleb on 6/16/24.
//

#ifndef DUALIE_DRAWABLE_HPP
#define DUALIE_DRAWABLE_HPP

#include <Dualie/System/Vector2.hpp>

namespace dl {

    /**
     * @brief The base class for any object that can be drawn to the screen
     */
    class Drawable {

    protected:
        bool m_bViewDoesAffect = true;

    public:

        /**
         * @brief Set whether the current view should affect the position of the drawable. Otherwise, its position
         * on the screen will be absolute
         * @param effective     Whether the view will be effective on this drawable
         */
        void viewShouldAffect(bool effective)
        {
            m_bViewDoesAffect = effective;
        }

        /**
         * @brief Draws the drawable to the screen
         * @param viewOffset    The offset of the current view to be used for internal drawable positioning
         */

        virtual void draw(const dl::Vector2f& viewOffset) = 0;


    };





}


#endif //DUALIE_DRAWABLE_HPP
