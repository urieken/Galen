#ifndef __RENDERER_H__
#define __RENDERER_H__

#include "vertex_array.h"
#include "index_buffer.h"
#include "shader_program.h"

class Renderer {
public:
	Renderer();
	virtual ~Renderer();

	void Clear() const;
	void Draw(const VertexArray& va, const IndexBuffer& ib, const ShaderProgram& shader) const;
};

#endif //__RENDERER_H__