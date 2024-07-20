//
// Created by caleb on 6/16/24.
//

#ifndef DUALIE_CIRCLESHAPE_HPP
#define DUALIE_CIRCLESHAPE_HPP

#include <Dualie/Graphics/Shape.hpp>

namespace dl{

class CircleShape : public dl::Shape{

public:
    CircleShape();
    CircleShape(float radius);

    void setRadius(float radius);

    void draw(const dl::Vector2f& viewOffset) const override;

protected:
    float m_radius;

};

}

#endif //DUALIE_CIRCLESHAPE_HPP
