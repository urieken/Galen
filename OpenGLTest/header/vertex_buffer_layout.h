#ifndef __VERTEX_BUFFER_LAYOUT_H__
#define __VERTEX_BUFFER_LAYOUT_H__

#include "core.h"
#include <vector>

struct VertexBufferElement {
	unsigned int type;
	unsigned int count;
	unsigned char normalized;
	static unsigned int GetSizeOfType(unsigned int type) {
		unsigned int size{ 0 };
		switch (type) {
		case GL_FLOAT: size = sizeof(GLfloat); break;
		case GL_UNSIGNED_INT: size = sizeof(GLuint); break;
		case GL_UNSIGNED_BYTE: size = sizeof(GLbyte); break;
		}
		//ASSERT(false);
		return size;
	}
};


typedef struct _vertexBufferElement {
	GLenum Type;
	GLuint Count;
	GLboolean Normalized;
	static GLuint SizeOf(GLenum type) {
		GLuint size{ 0 };
		switch (type)
		{
		case GL_FLOAT: {size = sizeof GLfloat; }break;
		case GL_UNSIGNED_INT: {size = sizeof GLuint; }break;
		case GL_BYTE: {size = sizeof GLbyte; }break;
		case GL_UNSIGNED_BYTE: {size = sizeof GLubyte; }break;
		default: {
			ASSERT(false);
		}break;
		}
	}
}VertexBufferElement_T;


class VertexBufferLayout {
	std::vector<VertexBufferElement> m_elements;
	unsigned int m_stride;
public:
	VertexBufferLayout();
	virtual ~VertexBufferLayout();

	template<typename _T>
	void Push(unsigned int count) {
		static_assert(false);
	}

	template<>
	void Push<float>(unsigned int count) {
		m_elements.push_back({ GL_FLOAT, count, GL_FALSE });
		m_stride += count * VertexBufferElement::GetSizeOfType(GL_FLOAT);
	}

	template<>
	void Push<unsigned int>(unsigned int count) {
		m_elements.push_back({ GL_UNSIGNED_INT, count, GL_FALSE });
		m_stride += count * VertexBufferElement::GetSizeOfType(GL_UNSIGNED_INT);
	}

	template<>
	void Push<unsigned char>(unsigned int count) {
		m_elements.push_back({ GL_UNSIGNED_BYTE, count, GL_TRUE });
		m_stride += count * VertexBufferElement::GetSizeOfType(GL_UNSIGNED_BYTE);
	}

	inline unsigned int GetStride() const { return m_stride; }
	inline const std::vector<VertexBufferElement> GetElements() const { return m_elements; }
};

#endif // __VERTEX_BUFFER_LAYOUT_H__
