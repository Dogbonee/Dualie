
//
// Created by caleb on 6/16/24.
//

#ifndef DUALIE_COLOR_HPP
#define DUALIE_COLOR_HPP

#include <citro2d.h>
#include <cstdint>

namespace dl {

    typedef u32 uint32_t;

    /**
     * @brief A class used to describe a RGBA color
     */
    class Color {

        u32 m_color;

    public:
        Color();
        Color(std::uint8_t red, std::uint8_t green, std::uint8_t blue, std::uint8_t alpha = 255);
        explicit Color(std::uint32_t color);

        /**
         * @brief Color values are stored as a 32 bit integer in the format ABGR, with A being shifted 24 bits, B 16 bits,
         * and so on.
         * @return  The color value as a 32 bit integer
         */
        const u32 & getColorValue() const;


        //Important constants
        static Color Black;       //!< Black predefined color
        static Color White;       //!< White predefined color
        static Color Red;         //!< Red predefined color
        static Color Green;       //!< Green predefined color
        static Color Blue;        //!< Blue predefined color
        static Color Yellow;      //!< Yellow predefined color
        static Color Magenta;     //!< Magenta predefined color
        static Color Cyan;        //!< Cyan predefined color
        static Color Transparent; //!< Transparent (black) predefined color

    };


}


#endif //DUALIE_COLOR_HPP
