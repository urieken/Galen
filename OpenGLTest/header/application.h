#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "core.h"
#include "shader_program.h"

#include <memory>
#include <vector>

class Application {
	GLFWwindow* m_pWindow;
	std::unique_ptr<ShaderProgram> m_pShaderProgram;

	unsigned int m_vao;
	unsigned int m_vbo;
	unsigned int m_ibo;

	bool CreateWindow();

public:
	Application();
	virtual ~Application();

	bool Initialize();
	int Run();
};

#endif // __APPLICATION_H__