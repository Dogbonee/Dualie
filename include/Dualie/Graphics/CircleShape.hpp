//
// Created by caleb on 6/16/24.
//

#ifndef DUALIE_CIRCLESHAPE_HPP
#define DUALIE_CIRCLESHAPE_HPP

#include <Dualie/Graphics/Shape.hpp>

namespace dl{

/**
 * @brief A circle shape
 */
class CircleShape : public dl::Shape{

public:
    CircleShape();


    CircleShape(float radius);

    /**
     * @brief Sets the radius of the circle
     * @param radius    Radius in pixels
     */
    void setRadius(float radius);

    void draw(const dl::Vector2f& viewOffset) override;

protected:
    float m_radius;

};

}

#endif //DUALIE_CIRCLESHAPE_HPP
