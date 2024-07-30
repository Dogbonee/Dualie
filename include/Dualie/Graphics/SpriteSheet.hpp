//
// Created by caleb on 7/28/24.
//

#ifndef DUALIE_SPRITESHEET_HPP
#define DUALIE_SPRITESHEET_HPP
#include <citro2d.h>
#include <string>


namespace dl
{
    /**
     * @brief A class used to load and contain t3x formatted spritesheets
     */
    class SpriteSheet
    {
        C2D_SpriteSheet m_spriteSheet;

    public:
        /**
         * @brief Loads a spritesheet from a t3x file
         * @param path  Path to load from
         */
        void loadFromFile(const std::string &path);
        C2D_SpriteSheet getSpriteSheet();

    };
}


#endif //DUALIE_SPRITESHEET_HPP
