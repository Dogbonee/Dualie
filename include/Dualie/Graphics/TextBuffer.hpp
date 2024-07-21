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

        friend class Text;
    };

}
#endif //DUALIE_TEXTBUFFER_HPP
