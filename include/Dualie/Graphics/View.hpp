//
// Created by caleb on 6/18/24.
//

#ifndef DUALIE_VIEW_H
#define DUALIE_VIEW_H


#include <Dualie/System/Rect.hpp>
#include <Dualie/System/Vector2.hpp>

namespace dl{

    /**
     * @brief Used as a camera-like object to move the screen view to different positions in world coordinates
     * @note This class is used to calculate the view offset, which is used in draw functions to offset object positions.
     * The default view offset is (0,0)
     */
    class View {

    private:
        dl::FloatRect m_viewRect;


    public:


        View();
        View(const dl::FloatRect& viewRect);

        /**
         * @brief Sets the view's viewrect to a new viewrect
         * @param viewRect  The viewrect to reset to
         */
        void reset(const dl::FloatRect& viewRect);

        /**
         * @brief Sets the center of the view's rect
         * @param center    The center to set
         */
        void setCenter(dl::Vector2f center);

        /**
         * @brief Moves the view offset number of pixels
         * @param offset    The offset to move
         */
        void move(dl::Vector2f offset);

        /**
         *
         * @return The view's render offset
         */
        dl::Vector2f getOffset();


    };

}


#endif //DUALIE_VIEW_H
