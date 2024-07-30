//
// Created by caleb on 7/20/24.
//

#include <Dualie/Graphics/TextBuffer.hpp>

dl::TextBuffer::TextBuffer(size_t bufSize)
{
    m_buffer = C2D_TextBufNew(bufSize);
}

dl::TextBuffer::~TextBuffer()
{
    C2D_TextBufDelete(m_buffer);
}

void dl::TextBuffer::flushBuffer()
{
    C2D_TextBufClear(m_buffer);
}


