#include "test_polygon_01_03.h"

namespace Test {

	void TestPolygon_01_03::SetupVertexBuffer()
	{
		LOG_SCOPE(__FUNCTION__);
		std::vector<float> vertices{
			// X     Y     R     G     B
			-0.5f, -0.5f, 1.0f, 0.0f, 1.0f,  // 0
			 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,  // 1
			 0.0f,  0.5f, 0.0f, 0.0f, 1.0f   // 2
		};
		m_pVB = std::make_unique<VertexBuffer>(
			reinterpret_cast<const void*>(vertices.data()),
			static_cast<unsigned int>(vertices.size() * sizeof(float)));
		m_pVB->SetVertexCount(3);
	}

	void TestPolygon_01_03::SetupLayout()
	{
		LOG_SCOPE(__FUNCTION__);
		m_pLayout = std::make_unique<VertexBufferLayout>();
		//m_pLayout->Push<float>(2);
		//m_pLayout->Push<float>(3);
                m_pLayout->Push(2, GL_FLOAT, GL_FALSE);
                m_pLayout->Push(3, GL_FLOAT, GL_FALSE);
	}

	void TestPolygon_01_03::SetupIndexBuffer()
	{
		std::vector<unsigned int> indices{
			2, 0, 1
		};
		m_pIB = std::make_unique<IndexBuffer>(
			reinterpret_cast<const unsigned int*>(indices.data()),
				static_cast<unsigned int>(indices.size()));
	}

	void TestPolygon_01_03::SetupShaders()
	{
		shader_map shaders;
		insert_shader(shaders,
			"res/shaders/test_polygon_01_03.vert", GL_VERTEX_SHADER);
		insert_shader(shaders,
			"res/shaders/test_polygon_01_03.frag", GL_FRAGMENT_SHADER);
		m_pShaders = std::make_unique<ShaderProgram>();
		if (m_pShaders->CompileShaders(shaders) && m_pShaders->LinkProgram()) {
			m_pShaders->Bind();
			LOG_INFO("position : %d", m_pShaders->GetAttributiteLocation("position"));
			LOG_INFO("color    : %d", m_pShaders->GetAttributiteLocation("color"));
			shaders.clear();
		}
	}

	TestPolygon_01_03::TestPolygon_01_03()
		: m_pIB{nullptr}
	{

	}

	TestPolygon_01_03::~TestPolygon_01_03()
	{

	}

	void TestPolygon_01_03::OnInitialize()
	{
		SetupVertexArray();
		SetupVertexBuffer();
		SetupIndexBuffer();
		SetupShaders();

		SetupLayout();
		m_pVA->AddBuffer(*m_pVB, *m_pLayout);

		m_pVA->UnBind();
		m_pVB->UnBind();
		m_pShaders->UnBind();

		SetupRenderer();
	}

	void TestPolygon_01_03::OnRender()
	{
		m_pRenderer->Clear();
		m_pRenderer->Draw(*m_pVA, *m_pIB, *m_pShaders);
	}

}
