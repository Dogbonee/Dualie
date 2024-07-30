//
// Created by caleb on 6/16/24.
//

#ifndef DUALIE_TRANSFORMABLE_HPP
#define DUALIE_TRANSFORMABLE_HPP


#include <Dualie/System/Vector2.hpp>

namespace dl {

    class Transformable {

    protected:
        dl::Vector2f m_position;


    public:
        virtual void setPosition(const dl::Vector2f& position);
        void setPosition(float x, float y);
        virtual void move(const dl::Vector2f& offset);
        void move(float xOffset, float yOffset);

        const dl::Vector2f& getPosition() const;

    };

}


#endif //DUALIE_TRANSFORMABLE_HPP
