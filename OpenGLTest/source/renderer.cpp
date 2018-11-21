#include "renderer.h"

Renderer::Renderer()
	: m_drawingMode{GL_TRIANGLES}
{

}

Renderer::~Renderer()
{

}

const unsigned int Renderer::GetDrawingMode() const
{
	return m_drawingMode;
}

void Renderer::SetDrawingMode(const unsigned int drawingMode)
{
	m_drawingMode = drawingMode;
}

void Renderer::SetPolygonMode(unsigned int face, unsigned int mode)
{
	GLCall(::glPolygonMode(face, mode));
}

void Renderer::SetClearColor(float r, float g, float b, float a)
{
	GLCall(::glClearColor(r, g, b, a));
}

void Renderer::Clear() const
{
	GLCall(::glClear(GL_COLOR_BUFFER_BIT));
}

void Renderer::Draw(const VertexArray& va, const IndexBuffer& ib, const ShaderProgram& shader) const
{
	va.Bind();
	ib.Bind();
	shader.Bind();
	GLCall(::glDrawElements(m_drawingMode, ib.GetCount(), GL_UNSIGNED_INT, nullptr));
}
