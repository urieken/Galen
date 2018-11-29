#include "vertex_buffer_layout.h"

VertexBufferLayout::VertexBufferLayout()
    : m_stride{ 0 }
{

}

VertexBufferLayout::~VertexBufferLayout()
{

}

void VertexBufferLayout::Push(unsigned int count, 
        GLenum type, bool normalized)
{
    LOG_SCOPE(__FUNCTION__);
    m_elements.push_back({ type, count, normalized });
    m_stride += count * VertexBufferElement::GetSizeOfType(type);
    LOG_INFO("STRIDE  : %d COUNT : %d SIZE : %d", 
            m_stride, count, VertexBufferElement::GetSizeOfType(type));
}

