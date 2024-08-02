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

    /**
     * @brief A class used to handle the drawing and transformation of sprites
     */
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

        /**
         * @brief Sets the origin of the shape. The default origin is (0,0) and is the top left pixel of the shape bounds.
         * Setting the origin can affect where the shape is drawn. For instance, setting the origin to be half the shape size
         * will cause the shape to be centered on its position.
         * @param origin    The origin in pixels
         */
        void setOrigin(const dl::Vector2f& origin);

        /**
         * @brief Sets the origin of the shape. The default origin is (0,0) and is the top left pixel of the shape bounds.
         * Setting the origin can affect where the shape is drawn. For instance, setting the origin to be half the shape size
         * will cause the shape to be centered on its position.
         * @param x    The origin in pixels (X)
         * @param y    The origin in pixels (Y)
         */
        void setOrigin(float x, float y);

        /**
         * @brief Sets the rotation of the sprite
         * @param rotation  The rotation in radians
         */
        void setRotation(const float &rotation);

        /**
         * @return The origin in pixels
         */
        const dl::Vector2f& getOrigin();

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
