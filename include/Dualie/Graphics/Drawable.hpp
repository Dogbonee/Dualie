//
// Created by caleb on 6/16/24.
//

#ifndef DUALIE_DRAWABLE_HPP
#define DUALIE_DRAWABLE_HPP

#include <Dualie/System/Vector2.hpp>

namespace dl {

    class Drawable {

    public:
        virtual void draw(const dl::Vector2f& viewOffset) = 0;


    };

}


#endif //DUALIE_DRAWABLE_HPP
