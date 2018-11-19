#include "index_buffer.h"

#include "core.h"
#include  "logger.h"

IndexBuffer::IndexBuffer(const unsigned int* pData, unsigned int count)
	: m_bufferId{ 0 }
	, m_count{ count }
{
	ASSERT(sizeof(unsigned int) == sizeof(GLuint));
	GLCall(::glGenBuffers(1, &m_bufferId));
	GLCall(::glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_bufferId));
	GLCall(::glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), pData, GL_STATIC_DRAW));
}

IndexBuffer::~IndexBuffer()
{
	GLCall(::glDeleteBuffers(1, &m_bufferId));
}

void IndexBuffer::Bind() const
{
	GLCall(::glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_bufferId));
}

void IndexBuffer::UnBind() const
{
	GLCall(::glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}



