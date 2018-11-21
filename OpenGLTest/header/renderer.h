#ifndef __RENDERER_H__
#define __RENDERER_H__

#include "vertex_array.h"
#include "index_buffer.h"
#include "shader_program.h"

class Renderer {
	unsigned int m_drawingMode;
public:
	Renderer();
	virtual ~Renderer();

	const unsigned int GetDrawingMode() const;
	void SetDrawingMode(const unsigned int drawingMode);

	void SetPolygonMode(unsigned int face, unsigned int mode);
	void SetClearColor(float r, float g, float b, float a);
	void Clear() const;
	void Draw(const VertexArray& va, const IndexBuffer& ib, const ShaderProgram& shader) const;
};

#endif //__RENDERER_H__