#include "vertex_array.h"

#include <array>

VertexArray::VertexArray()
	: m_arrays{}
	//, m_arrayId{ 0 }
{
	GLuint array;
	GLCall(::glGenVertexArrays(1, &array));
	m_arrays.push_back(array);
}

VertexArray::VertexArray(const GLuint& count)
	: m_arrays{}
	//, m_arrayId{ 0 }
{
	for (GLuint i = 0; i < count; i++) {
		GLuint array;
		GLCall(::glGenVertexArrays(1, &array));
		m_arrays.push_back(array);
	}
}


VertexArray::~VertexArray()
{
	GLCall(::glDeleteVertexArrays(static_cast<GLuint>(m_arrays.size()), m_arrays.data()));
}

void VertexArray::AddBuffer(GLuint index, 
	const VertexBuffer& vertexBuffer, 
	const VertexBufferLayout& layout)
{
	Bind(index);
	vertexBuffer.Bind();
	const std::vector<VertexBufferElement> elements{ layout.GetElements() };
	unsigned int offset{0};
	for (int i = 0; i < elements.size(); i++) {
		void const* pointer{static_cast<char const*>(0) + offset};
		GLCall(::glEnableVertexAttribArray(i));
		GLCall(::glVertexAttribPointer(i, elements[0].count, elements[i].type,
			elements[i].normalized, layout.GetStride(), pointer));
		offset += elements[i].count * VertexBufferElement::GetSizeOfType(elements[i].type);
	}
}

void VertexArray::Bind(GLuint index) const {
	GLCall(::glBindVertexArray(m_arrays[index]));
}

void VertexArray::UnBind() const {
	GLCall(::glBindVertexArray(0));
}
