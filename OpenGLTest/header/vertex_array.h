#ifndef __VERTEX_ARRAY_H__
#define __VERTEX_ARRAY_H__

#include "vertex_buffer.h"
#include "vertex_buffer_layout.h"

class VertexArray {
	unsigned int m_arrayId;
public:
	VertexArray();
	virtual ~VertexArray();

	void AddBuffer(const VertexBuffer& vertexBuffer, const VertexBufferLayout& layout);

	void Bind() const;
	void UnBind() const;
};

#endif // __VERTEX_ARRAY_H__