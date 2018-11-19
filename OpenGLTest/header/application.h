#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "core.h"

#include "index_buffer.h"
#include "vertex_array.h"
#include "vertex_buffer.h"
#include "shader_program.h"

class Application {
	GLFWwindow* m_pWindow;

	std::unique_ptr<ShaderProgram>      m_pShaderProgram;
	std::unique_ptr<VertexArray>        m_pVertexArray;
	std::unique_ptr<VertexBuffer>       m_pVertexBuffer;
	std::unique_ptr<VertexBufferLayout> m_pVertexBufferLayout;
	std::unique_ptr<IndexBuffer>        m_pIndexBuffer;

	bool CreateWindow();

public:
	Application();
	virtual ~Application();

	bool Initialize();
	void SetupBuffers();
	int Run();
};

#endif // __APPLICATION_H__