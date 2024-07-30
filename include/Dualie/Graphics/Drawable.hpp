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

    public:
        /**
         * @brief Draws the drawable to the screen
         * @param viewOffset    The offset of the current view to be used for internal drawable positioning
         */
        virtual void draw(const dl::Vector2f& viewOffset) = 0;


    };

}


#endif //DUALIE_DRAWABLE_HPP
