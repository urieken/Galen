#include "renderer.h"

Renderer::Renderer()
{

}

Renderer::~Renderer()
{

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
	GLCall(::glDrawElements(GL_TRIANGLES, ib.GetCount(), GL_UNSIGNED_INT, nullptr));
}
