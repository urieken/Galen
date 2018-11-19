#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "texture.h"
#include "renderer.h"
#include "index_buffer.h"
#include "vertex_array.h"
#include "vertex_buffer.h"
#include "shader_program.h"

#include "gtc/matrix_transform.hpp"

#include "imgui.h"

class Application {
	GLFWwindow* m_pWindow;

	std::unique_ptr<ShaderProgram>      m_pShader;
	std::unique_ptr<VertexArray>        m_pVA;
	std::unique_ptr<VertexBuffer>       m_pVB;
	std::unique_ptr<VertexBufferLayout> m_pLayout;
	std::unique_ptr<IndexBuffer>        m_pIB;
	std::unique_ptr<Renderer>           m_pRenderer;
	std::unique_ptr<Texture>            m_pTexture;

	glm::mat4 m_proj;
	glm::mat4 m_view;
	glm::mat4 m_model;

	bool CreateWindow();
	void InitializeImGui();
	void CreateImGuiFrame();
	void DrawImGui(glm::vec3& trans_a, glm::vec3& trans_b, ImVec4& clear_color);
	void RenderImGui();
	void DestroyImGui();

public:
	Application();
	virtual ~Application();

	bool Initialize();
	void SetupBuffers();
	int Run();
};

#endif // __APPLICATION_H__