#include "vertex_array.h"

VertexArray::VertexArray()
	: m_arrayId{ 0 }
{
	GLCall(::glGenVertexArrays(1, &m_arrayId));
}


VertexArray::~VertexArray()
{
	GLCall(::glDeleteVertexArrays(1, &m_arrayId));
}

void VertexArray::AddBuffer(const VertexBuffer& vertexBuffer, const VertexBufferLayout& layout)
{
	Bind();
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

void VertexArray::Bind() const {
	GLCall(::glBindVertexArray(m_arrayId));
}

void VertexArray::UnBind() const {
	GLCall(::glBindVertexArray(0));
}
