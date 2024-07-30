//
// Created by caleb on 6/17/24.
//

#ifndef DUALIE_RECTANGLESHAPE_HPP
#define DUALIE_RECTANGLESHAPE_HPP


#include <Dualie/Graphics/Shape.hpp>

namespace dl {

    class RectangleShape : public dl::Shape {


    public:
        RectangleShape();

        RectangleShape(const dl::Vector2f &size);

        void setSize(const dl::Vector2f &size);

        void draw(const dl::Vector2f& viewOffset) override;

    };

}

#endif //DUALIE_RECTANGLESHAPE_HPP
