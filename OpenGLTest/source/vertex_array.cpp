#include "vertex_array.h"

#include <array>

VertexArray::VertexArray()
	//: m_arrays{}
	: m_arrayId{ 0 }
{
	//GLuint array;
	GLCall(::glGenVertexArrays(1, &m_arrayId));
	//m_arrays.push_back(array);
}

//VertexArray::VertexArray(const GLuint& count)
//	: m_arrays{}
//	//, m_arrayId{ 0 }
//{
//	for (GLuint i = 0; i < count; i++) {
//		GLuint array;
//		GLCall(::glGenVertexArrays(1, &array));
//		m_arrays.push_back(array);
//	}
//}


VertexArray::~VertexArray()
{
	GLCall(::glDeleteVertexArrays(1, &m_arrayId));
}

void VertexArray::AddBuffer(const VertexBuffer& vertexBuffer, 
	const VertexBufferLayout& layout)
{
	Bind();
	vertexBuffer.Bind();
	const std::vector<VertexBufferElement> elements{ layout.GetElements() };
	unsigned int offset{0};
	for (int i = 0; i < elements.size(); i++) {
		void const* pointer{static_cast<char const*>(0) + offset};
		LOG_INFO("COUNT    : %d", elements[i].count);
		LOG_INFO("OFFSET   : %d", offset);
		LOG_INFO("STRIDE   : %d", layout.GetStride());
		GLCall(::glEnableVertexAttribArray(i));
		GLCall(::glVertexAttribPointer(i, elements[i].count, elements[i].type,
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
