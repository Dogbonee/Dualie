//
// Created by caleb on 7/28/24.
//

#ifndef DUALIE_SPRITE_HPP
#define DUALIE_SPRITE_HPP
#include <citro2d.h>
#include <Dualie/Graphics/Transformable.hpp>
#include <Dualie/Graphics/Drawable.hpp>
#include <Dualie/Graphics/SpriteSheet.hpp>


namespace dl
{

    class Sprite : public dl::Transformable, public dl::Drawable
    {

        C2D_Sprite m_sprite{};
        float m_rotation{};
        dl::Vector2f m_origin;

    public:

        Sprite();

        void loadFromSpriteSheet(SpriteSheet spriteSheet, size_t index);

        void draw(const dl::Vector2f &viewOffset) override;
        void setPosition(const dl::Vector2f &position) override;
        void move(const dl::Vector2f &offset) override;
        void setRotation(const float &rotation);
        const float &getRotation();
        void rotate(const float &rotationOffset);

        friend C2D_SpriteSheet SpriteSheet::getSpriteSheet();


    };

}


#endif //DUALIE_SPRITE_HPP
