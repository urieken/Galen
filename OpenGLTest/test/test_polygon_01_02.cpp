#include "test_polygon_01_02.h"

namespace Test {

	void TestPolygon_01_02::SetupShaders()
	{
		shader_map shaders;
		insert_shader(shaders,
			"res/shaders/test_polygon_01_01.vert", GL_VERTEX_SHADER);
		insert_shader(shaders,
			"res/shaders/test_polygon_01_02.frag", GL_FRAGMENT_SHADER);
		m_pShaders = std::make_unique<ShaderProgram>();
		if (m_pShaders->CompileShaders(shaders) && m_pShaders->LinkProgram()) {
			m_pShaders->Bind();
			shaders.clear();
		}
	}

	TestPolygon_01_02::TestPolygon_01_02()
	{
		
	}

	TestPolygon_01_02::~TestPolygon_01_02()
	{

	}

	void TestPolygon_01_02::OnInitialize()
	{
		LOG_SCOPE(__FUNCTION__);
		m_timeStart = std::chrono::high_resolution_clock::now();
		SetupVertexArray();
		SetupVertexBuffer();
		SetupLayout();
		m_pVA->AddBuffer(*m_pVB, *m_pLayout);
		SetupShaders();

		m_pVA->UnBind();
		m_pVB->UnBind();
		m_pShaders->UnBind();

		SetupRenderer();
	}

	void TestPolygon_01_02::OnUpdate(float delta_time) {
		std::chrono::time_point<std::chrono::steady_clock> timeNow{
			std::chrono::high_resolution_clock::now() };
		float time{ std::chrono::duration_cast<std::chrono::duration<float>>(timeNow - m_timeStart).count() };
		LOG_INFO("TIME : %f", (std::sinf(time * 4.0f) + 1.0f) / 2.0f);
		m_pShaders->SetUniform1f("u_Color", (std::sinf(time * 4.0f) + 1.0f) / 2.0f);
	}
}