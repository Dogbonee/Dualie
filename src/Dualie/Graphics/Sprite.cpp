//
// Created by caleb on 7/28/24.
//

#include <Dualie/Graphics/Sprite.hpp>

dl::Sprite::Sprite()
{
    C2D_SpriteSetCenter(&m_sprite, 0.f,0.f);
}



void dl::Sprite::setPosition(const dl::Vector2f &position)
{
    Transformable::setPosition(position);
}

void dl::Sprite::move(const dl::Vector2f &offset)
{
    Transformable::move(offset);
}

void dl::Sprite::setRotation(const float &rotation)
{
    m_rotation = rotation;
    C2D_SpriteSetRotation(&m_sprite, rotation);
}

void dl::Sprite::rotate(const float &rotationOffset)
{
    m_rotation += rotationOffset;
    C2D_SpriteRotate(&m_sprite, rotationOffset);
}



const float& dl::Sprite::getRotation()
{
    return m_rotation;
}


void dl::Sprite::draw(const dl::Vector2f &viewOffset)
{
    auto vo = m_bViewDoesAffect ? viewOffset : dl::Vector2f(0,0);
    C2D_SpriteSetPos(&m_sprite, m_position.x - m_origin.x - vo.x, m_position.y - m_origin.y - vo.y);
    C2D_DrawSprite(&m_sprite);
}

void dl::Sprite::loadFromSpriteSheet(SpriteSheet spriteSheet, size_t index)
{
    C2D_SpriteFromSheet(&m_sprite, spriteSheet.getSpriteSheet(), index);
}

void dl::Sprite::setOrigin(const dl::Vector2f &origin)
{
    m_origin = origin;
}

void dl::Sprite::setOrigin(float x, float y)
{
    m_origin = dl::Vector2f(x,y);
}

const dl::Vector2f &dl::Sprite::getOrigin()
{
    return m_origin;
}




