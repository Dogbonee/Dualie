//
// Created by caleb on 6/18/24.
//

#ifndef DUALIE_RECT_HPP
#define DUALIE_RECT_HPP

#include <Dualie/System/Vector2.hpp>

namespace dl {

    template<class T>
    class Rect {
        using FloatRect = Rect<float>;
    public:
        T left;
        T top;
        T width;
        T height;

        Rect() {

            left = 0;
            top = 0;
            width = 0;
            height = 0;

        }

        Rect(T left, T top, T width, T height) {

            this->left = left;
            this->top = top;
            this->width = width;
            this->height = height;
        }
        Rect(dl::Vector2<T> position, dl::Vector2<T> size) {

            left = position.x;
            top = position.y;
            width = size.x;
            height = size.y;
        }

        Rect(const dl::Rect<T> &rect) {
            *this = rect;
        }

        /**
         * @brief Returns whether a rect intersects the bounds of this rect
         * @param rect  The rect to check
         * @return Whether the rect intersects this rect's bounds
         */
        bool intersects(Rect<T> rect){
            return (this->left < rect.left + rect.width && this->left + this->width > rect.left &&
            this->top < rect.top + rect.height && this->top + this->height > rect.top);
        }

        /**
         * @brief Returns whether a point intersects the bounds of this rect
         * @param point The point to check
         * @return Whether the point intersects this rect's bounds
         */
        bool contains(dl::Vector2<T> point){
            return (point.x > this->left && point.x < this->left + this->width && point.y > this->top && point.y < this->top + this->height);
        }

    };
    using FloatRect = Rect<float>;
}

#endif //DUALIE_RECT_HPP
