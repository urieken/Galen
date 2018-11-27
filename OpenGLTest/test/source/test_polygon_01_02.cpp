#include "test_polygon_01_02.h"

#include "glm.hpp"
#include "gtc/type_ptr.hpp"

#include <cmath>

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
		: m_deltaTime{0.0f}
	{
		
	}

	TestPolygon_01_02::~TestPolygon_01_02()
	{

	}

	void TestPolygon_01_02::OnInitialize()
	{
		LOG_SCOPE(__FUNCTION__);
		
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

		m_deltaTime += 0.05f;
		if(m_deltaTime > 360.0f){
			m_deltaTime = 0.0f;
		}
		
        glm::vec3 color{ (std::sin(m_deltaTime  * 0.5f) + 0.5f), 0.0f, 0.0f };
        //glm::vec3 color{ 0.5f, 0.0f, 0.0f };
		m_pShaders->Bind();
		m_pShaders->SetUniform3fv("u_Color", glm::value_ptr(color));
	}
}
