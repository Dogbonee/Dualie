//
// Created by caleb on 6/16/24.
//

#ifndef DUALIE_VECTOR2_HPP
#define DUALIE_VECTOR2_HPP

#include <string>

namespace dl{

template<class T> class Vector2 {

public:

    T x;
    T y;

    Vector2() {
        x = 0;
        y = 0;
    }

    Vector2(T x, T y) {
        this->x = x;
        this->y = y;
    }

    dl::Vector2<T> operator+(dl::Vector2<T> vector) const {

        return dl::Vector2<T>(this->x + vector.x, this->y + vector.y);
    }
    dl::Vector2<T> operator-(dl::Vector2<T> vector) const {
        return dl::Vector2<T>(this->x - vector.x, this->y - vector.y);
    }
    dl::Vector2<T> operator*(dl::Vector2<T> vector) const {
        return dl::Vector2<T>(this->x * vector.x, this->y * vector.y);
    }
    dl::Vector2<T> operator/(dl::Vector2<T> vector) const {
        return dl::Vector2<T>(this->x / vector.x, this->y / vector.y);
    }

    std::string toString() const {
        return "(" + std::to_string((int)x) + ", " + std::to_string((int)y) + ")";
    }

};



    using Vector2f = dl::Vector2<float>;
    using Vector2i = dl::Vector2<int>;
}



#endif //DUALIE_VECTOR2_HPP
