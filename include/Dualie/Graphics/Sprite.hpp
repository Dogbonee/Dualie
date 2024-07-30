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

        /**
         * @brief Loads an image into the sprite from a spritesheet
         * @param spriteSheet   The spritesheet to target
         * @param index     The image index of the spritesheet
         */
        void loadFromSpriteSheet(SpriteSheet spriteSheet, size_t index);

        /**
         * @brief Sets the position of the sprite
         * @param position  The position to set
         */
        void setPosition(const dl::Vector2f &position) override;

        /**
         * @brief Moves the sprite offset number of pixels.
         * @param offset    The offset to move
         */
        void move(const dl::Vector2f &offset) override;

        /**
         * @brief Sets the rotation of the sprite in radians
         * @param rotation  The rotation to set (in radians)
         */
        void setRotation(const float &rotation);

        /**
         * @return The sprite's rotation in radians
         */
        const float &getRotation();

        /**
         * @brief Rotates the sprite on top of its current rotation
         * @param rotationOffset    The rotation in radians to rotate
         */
        void rotate(const float &rotationOffset);

        void draw(const dl::Vector2f &viewOffset) override;

        friend C2D_SpriteSheet SpriteSheet::getSpriteSheet();


    };

}


#endif //DUALIE_SPRITE_HPP
