//
// Created by caleb on 7/20/24.
//

#ifndef DUALIE_TEXTBUFFER_HPP
#define DUALIE_TEXTBUFFER_HPP
#include <citro2d.h>

namespace dl
{
    class TextBuffer
    {

        C2D_TextBuf m_buffer;

    public:
        explicit TextBuffer(size_t bufSize);
        ~TextBuffer();

        /**
         * @brief flushes the text buffer. This should be done if the text changes frequently, such as a timer or FPS
         * counter. Note that after this is done all text that use this buffer should be either be updated using
         * Text::updateDynamicText or reset using Text::setString.
         */
        void flushBuffer();

        friend class Text;
    };

}
#endif //DUALIE_TEXTBUFFER_HPP
