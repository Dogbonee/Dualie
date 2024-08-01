//
// Created by caleb on 7/31/24.
//
#include <Dualie/Graphics/Drawable.hpp>

void dl::Drawable::viewShouldAffect(bool effective)
{
    m_bViewDoesAffect = effective;
}

void dl::Drawable::setDepth(float depth)
{
    m_depth = depth;
}

const float &dl::Drawable::getDepth() const
{
    return m_depth;
}
