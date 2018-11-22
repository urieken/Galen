#ifndef __VERTEX_ARRAY_H__
#define __VERTEX_ARRAY_H__

#include "vertex_buffer.h"
#include "vertex_buffer_layout.h"

class VertexArray {
	//std::vector<GLuint> m_arrays;
	unsigned int m_arrayId;
public:
	VertexArray();
	//VertexArray(const GLuint& count);
	virtual ~VertexArray();

	void AddBuffer(const VertexBuffer& vertexBuffer,
		const VertexBufferLayout& layout);

	void Bind() const;
	void UnBind() const;
};

#endif // __VERTEX_ARRAY_H__