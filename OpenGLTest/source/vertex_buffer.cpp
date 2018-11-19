#include "vertex_buffer.h"

#include "core.h"
#include  "logger.h"

VertexBuffer::VertexBuffer(const void* pData, unsigned int size)
	: m_bufferId{ 0 }
{
	GLCall(::glGenBuffers(1, &m_bufferId));
	GLCall(::glBindBuffer(GL_ARRAY_BUFFER, m_bufferId));
	GLCall(::glBufferData(GL_ARRAY_BUFFER, size, pData, GL_STATIC_DRAW));
}

VertexBuffer::~VertexBuffer()
{
	GLCall(::glDeleteBuffers(1, &m_bufferId));
}

void VertexBuffer::Bind() const
{
	GLCall(::glBindBuffer(GL_ARRAY_BUFFER, m_bufferId));
}

void VertexBuffer::UnBind() const
{
	GLCall(::glBindBuffer(GL_ARRAY_BUFFER, 0));
}



