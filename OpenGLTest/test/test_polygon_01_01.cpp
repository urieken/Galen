#include "test_polygon_01_01.h"

#include "imgui.h"

namespace Test {

	void TestPolygon_01_01::SetupVertexArray()
	{
		LOG_SCOPE(__FUNCTION__);
		m_pVA = std::make_unique<VertexArray>();
	}

	void TestPolygon_01_01::SetupVertexBuffer()
	{
		LOG_SCOPE(__FUNCTION__);
		std::vector<float> vertices{
			// X     Y
			-0.5f, -0.5f,   // 0
			 0.5f, -0.5f,   // 1
			 0.0f,  0.5f    // 2
		};
		m_pVB = std::make_unique<VertexBuffer>(
			reinterpret_cast<const void*>(vertices.data()),
			static_cast<unsigned int>(vertices.size() * sizeof(float)));
		m_pVB->SetVertexCount(3);
	}

	void TestPolygon_01_01::SetupLayout()
	{
		LOG_SCOPE(__FUNCTION__);
		m_pLayout = std::make_unique<VertexBufferLayout>();
		m_pLayout->Push<float>(2);
	}

	void TestPolygon_01_01::SetupShaders()
	{
		shader_map shaders;
		insert_shader(shaders,
			"res/shaders/test_polygon_01_01.vert", GL_VERTEX_SHADER);
		insert_shader(shaders,
			"res/shaders/test_polygon_01_01.frag", GL_FRAGMENT_SHADER);
		m_pShaders = std::make_unique<ShaderProgram>();
		if (m_pShaders->CompileShaders(shaders) && m_pShaders->LinkProgram()) {
			m_pShaders->Bind();
			shaders.clear();
		}
	}

	void TestPolygon_01_01::SetupRenderer()
	{
		m_pRenderer = std::make_unique<Renderer>();
		m_pRenderer->SetClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	}

	TestPolygon_01_01::TestPolygon_01_01()
		: m_pVA{ nullptr }
		, m_pVB{ nullptr }
		, m_pLayout{ nullptr }
		, m_pShaders{ nullptr }
		, m_pRenderer{ nullptr }
	{

	}

	TestPolygon_01_01::~TestPolygon_01_01()
	{

	}

	void TestPolygon_01_01::OnInitialize()
	{
		SetupVertexArray();
		SetupVertexBuffer();
		SetupLayout();
		m_pVA->AddBuffer(0, *m_pVB, *m_pLayout);
		SetupShaders();

		m_pVA->UnBind();
		m_pVB->UnBind();
		m_pShaders->UnBind();

		SetupRenderer();
	}

	void TestPolygon_01_01::OnUpdate(float delta_time)
	{

	}

	void TestPolygon_01_01::OnRender()
	{
		m_pRenderer->Clear();
		m_pRenderer->Draw(*m_pVA, *m_pVB, *m_pShaders);
	}

	void TestPolygon_01_01::OnImGuiRender()
	{
		ImGui::Text("Application average %.3f ms/frame (%.1f FPS)",
			1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
	}

}