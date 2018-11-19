#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "texture.h"
#include "renderer.h"
#include "index_buffer.h"
#include "vertex_array.h"
#include "vertex_buffer.h"
#include "shader_program.h"

class Application {
	GLFWwindow* m_pWindow;

	std::unique_ptr<ShaderProgram>      m_pShader;
	std::unique_ptr<VertexArray>        m_pVA;
	std::unique_ptr<VertexBuffer>       m_pVB;
	std::unique_ptr<VertexBufferLayout> m_pLayout;
	std::unique_ptr<IndexBuffer>        m_pIB;
	std::unique_ptr<Renderer>           m_pRenderer;
	std::unique_ptr<Texture>            m_pTexture;

	bool CreateWindow();

public:
	Application();
	virtual ~Application();

	bool Initialize();
	void SetupBuffers();
	int Run();
};

#endif // __APPLICATION_H__