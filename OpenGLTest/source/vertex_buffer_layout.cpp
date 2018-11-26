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
    m_elements.push_back({ type, count, normalized });
    m_stride += count * VertexBufferElement::GetSizeOfType(type);
}

