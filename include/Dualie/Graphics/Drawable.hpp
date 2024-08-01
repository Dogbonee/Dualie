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
        float m_depth = 0.0f;

    public:

        /**
         * @brief Set whether the current view should affect the position of the drawable. Otherwise, its position
         * on the screen will be absolute
         * @param effective     Whether the view will be effective on this drawable
         */
        void viewShouldAffect(bool effective);


        /**
         * @brief Sets the depth of the drawable for 3d. This simply corresponds to the X offset calculated for the 2 separate
         * top screens. Larger objects will require a deeper depth for the 3d effect to be noticable. A positive value will cause
         * the drawable to sink into the screen, while a negative value will cause it to pop out.
         * @param depth     The depth of the object
         */
        void setDepth(float depth);

        /**
         *
         * @return  The depth of the drawable
         */
        const float& getDepth() const;

        /**
         * @brief Draws the drawable to the screen
         * @param viewOffset    The offset of the current view to be used for internal drawable positioning
         */

        virtual void draw(const dl::Vector2f& viewOffset) = 0;


    };





}


#endif //DUALIE_DRAWABLE_HPP
