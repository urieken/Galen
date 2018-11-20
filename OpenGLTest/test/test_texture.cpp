#include "test_texture.h"

#include "gtc/matrix_transform.hpp"


namespace Test {

	void TestTexture::SetupBuffers()
	{
		LOG_SCOPE(__FUNCTION__);

		std::vector<float> vertices = {
			-0.5f,  0.5f, 0.0f, 1.0f,
			-0.5f, -0.5f, 0.0f, 0.0f,
			0.5f, -0.5f, 1.0f, 0.0f,
			0.5f,  0.5f, 1.0f, 1.0f
		};
		std::vector<unsigned int> indices = {
			0, 1, 2,
			2, 3, 0
		};

		m_pVA = std::make_unique<VertexArray>();

		m_pVB = std::make_unique<VertexBuffer>(
			reinterpret_cast<const void*>(vertices.data()),
			static_cast<unsigned int>(vertices.size() * sizeof(float)));

		m_pLayout = std::make_unique<VertexBufferLayout>();
		m_pLayout->Push<float>(2);
		m_pLayout->Push<float>(2);
		m_pVA->AddBuffer(*m_pVB.get(), *m_pLayout.get());

		m_pIB = std::make_unique<IndexBuffer>(
			reinterpret_cast<const unsigned int*>(indices.data()),
			static_cast<unsigned int>(indices.size() * 2));

		shader_map shaders;
		insert_shader(shaders, "res/shaders/test.vert", GL_VERTEX_SHADER);
		insert_shader(shaders, "res/shaders/test.frag", GL_FRAGMENT_SHADER);

		m_proj = glm::ortho(-2.0f, 2.0f, -1.5f, 1.5f, -1.0f, 1.0f);
		m_view = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f));

		m_pShader = std::make_unique<ShaderProgram>();
		if (m_pShader->CompileShaders(shaders) && m_pShader->LinkProgram()) {
			m_pShader->Bind();
			shaders.clear();

			m_pTexture = std::make_unique<Texture>("res/images/cpp.png");
			m_pTexture->Bind();
			m_pShader->SetUniform1i("u_Texture", 0);
		}

		m_pVA->UnBind();
		m_pVB->UnBind();
		m_pIB->UnBind();
		m_pShader->UnBind();

		m_pRenderer = std::make_unique<Renderer>();
		m_pRenderer->SetClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	}

	TestTexture::TestTexture()
		: TestBase{}
		, m_pShader{ nullptr }
		, m_pVA{ nullptr }
		, m_pVB{ nullptr }
		, m_pLayout{ nullptr }
		, m_pIB{ nullptr }
		, m_pRenderer{ nullptr }
		, m_pTexture{ nullptr }
		, m_red{ 0.0f }
		, m_increment{ 0.0f }
		, m_trans_a{ 0.5f,  0.0f,  0.0f }
		, m_trans_b{ -0.5f,  0.0f,  0.0f }
		, m_clear_color{ 0.45f, 0.55f, 0.60f, 1.00f }
	{
		LOG_SCOPE(__FUNCTION__);
		SetupBuffers();
	}

	TestTexture::~TestTexture()
	{
		LOG_SCOPE(__FUNCTION__);
	}

	void TestTexture::OnUpdate(float delta_time)
	{
		m_model = glm::translate(glm::mat4(1.0f), m_trans_a);
		m_model = glm::translate(glm::mat4(1.0f), m_trans_b);

		glm::mat4 mvp{ m_model * m_view * m_proj };

		if (1.0f < m_red) {
			m_increment = -0.01f;
		}
		else if (0.0f > m_red) {
			m_increment = 0.01f;
		}
	}

	void TestTexture::OnRender()
	{
		m_pRenderer->Clear();
		m_pShader->Bind();
		m_pShader->SetUniform4f("u_Color", m_red, 0.3f, 0.8f, 1.0f);
		{
			m_model = glm::translate(glm::mat4(1.0f), m_trans_a);
			glm::mat4 mvp{ m_model * m_view * m_proj };
			m_pShader->SetUniformMat4f("u_MVP", &mvp[0][0]);
			m_pRenderer->Draw(*m_pVA.get(), *m_pIB.get(), *m_pShader.get());
		}
		{
			m_model = glm::translate(glm::mat4(1.0f), m_trans_b);
			glm::mat4 mvp{ m_model * m_view * m_proj };
			m_pShader->SetUniformMat4f("u_MVP", &mvp[0][0]);
			m_pRenderer->Draw(*m_pVA.get(), *m_pIB.get(), *m_pShader.get());
		}

	}

	void TestTexture::OnImGuiRender()
	{
		ImGui::SliderFloat3("Translation A", &m_trans_a.x, -1.0f, 1.0f);
		ImGui::SliderFloat3("Translation B", &m_trans_b.x, -1.0f, 1.0f);

		ImGui::ColorEdit3("clear color", (float*)&m_clear_color);
		m_pRenderer->SetClearColor(m_clear_color.x, m_clear_color.y, 
			m_clear_color.z, m_clear_color.w);
		ImGui::Text("Application average %.3f ms/frame (%.1f FPS)",
			1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
	}

}