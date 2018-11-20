#include "test_triangle.h"

#include "imgui.h"

namespace Test {

	void TestTriangle::SetupRenderer()
	{
		m_pRenderer = std::make_unique<Renderer>();
		m_pRenderer->SetClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	}

	void TestTriangle::SetupShaders()
	{
		shader_map shaders;
		insert_shader(shaders, "res/shaders/hello_triangle.vert", GL_VERTEX_SHADER);
		insert_shader(shaders, "res/shaders/hello_triangle.frag", GL_FRAGMENT_SHADER);
		m_pShader = std::make_unique<ShaderProgram>();
		if (m_pShader->CompileShaders(shaders) && m_pShader->LinkProgram()) {
			m_pShader->Bind();
			shaders.clear();
		}
	}

	void TestTriangle::SetupIndexBuffer()
	{
		LOG_SCOPE(__FUNCTION__);
		std::vector<unsigned int> indices = {
			0, 1, 2
		};
		m_pIB = std::make_unique<IndexBuffer>(
			reinterpret_cast<const unsigned int*>(indices.data()),
			static_cast<unsigned int>(indices.size() * 2));
	}

	void TestTriangle::SetupLayout() 
	{
		LOG_SCOPE(__FUNCTION__);
		m_pLayout = std::make_unique<VertexBufferLayout>();
		m_pLayout->Push<float>(3);
	}

	void TestTriangle::SetupVertexBuffer()
	{
		LOG_SCOPE(__FUNCTION__);
		std::vector<float> vertices = {
			-0.5f, -0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			 0.0f,  0.5f, 0.0f
		};
		m_pVB = std::make_unique<VertexBuffer>(
			reinterpret_cast<const void*>(vertices.data()),
			static_cast<unsigned int>(vertices.size() * sizeof(float)));
	}

	void TestTriangle::SetupBuffers()
	{
		LOG_SCOPE(__FUNCTION__);
		m_pVA = std::make_unique<VertexArray>();
		SetupVertexBuffer();
		SetupLayout();
		m_pVA->AddBuffer(*m_pVB, *m_pLayout);
		SetupIndexBuffer();
		SetupShaders();

		m_pVA->UnBind();
		m_pVB->UnBind();
		m_pIB->UnBind();
		m_pShader->UnBind();

		SetupRenderer();
	}

	TestTriangle::TestTriangle()
		: m_pVA{ nullptr }
		, m_pVB{ nullptr }
		, m_pLayout{ nullptr }
		, m_pIB{ nullptr }
		, m_pShader{ nullptr }
		, m_pRenderer{ nullptr }
	{
		LOG_SCOPE(__FUNCTION__);
		SetupBuffers();
	}

	TestTriangle::~TestTriangle()
	{

	}

	void TestTriangle::OnUpdate(float delta_time)
	{

	}

	void TestTriangle::OnRender()
	{
		m_pRenderer->Clear();
		m_pRenderer->Draw(*m_pVA, *m_pIB, *m_pShader);
	}

	void TestTriangle::OnImGuiRender()
	{
		ImGui::Text("Application average %.3f ms/frame (%.1f FPS)",
			1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
	}

}