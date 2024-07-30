//
// Created by caleb on 7/28/24.
//

#include <Dualie/Graphics/SpriteSheet.hpp>

C2D_SpriteSheet dl::SpriteSheet::getSpriteSheet()
{
    return m_spriteSheet;
}

void dl::SpriteSheet::loadFromFile(const std::string &path)
{
    m_spriteSheet = C2D_SpriteSheetLoad(path.c_str());
    if(!m_spriteSheet){
        printf("Failed to load spritesheet\n");
    }
}
