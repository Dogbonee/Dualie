//
// Created by caleb on 7/28/24.
//

#include <Dualie/Graphics/SpriteSheet.hpp>

dl::SpriteSheet::SpriteSheet() = default;

dl::SpriteSheet::~SpriteSheet()
{
    C2D_SpriteSheetFree(m_spriteSheet);
}

bool dl::SpriteSheet::loadFromFile(const std::string &path)
{
    m_spriteSheet = C2D_SpriteSheetLoad(path.c_str());
    return m_spriteSheet != nullptr;
}

C2D_SpriteSheet dl::SpriteSheet::getSpriteSheet()
{
    return m_spriteSheet;
}
