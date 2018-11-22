#include "test_triangle_01_03.h"

namespace Test {

	void TestTriangle_01_03::SetupShaders()
	{
		LOG_SCOPE(__FUNCTION__);
		shader_map shaders;
		
		insert_shader(shaders, "res/shaders/test_triangle_01_02.vert", GL_VERTEX_SHADER);
		insert_shader(shaders, "res/shaders/test_triangle_01_02.frag", GL_FRAGMENT_SHADER);
		m_shaders.push_back(std::make_unique<ShaderProgram>());
		m_shaders.push_back(std::make_unique<ShaderProgram>());
		if (m_shaders[0]->CompileShaders(shaders) && m_shaders[0]->LinkProgram()) {
			shaders.clear();
		}
		insert_shader(shaders, "res/shaders/test_triangle_01_02.vert", GL_VERTEX_SHADER);
		insert_shader(shaders, "res/shaders/test_triangle_01_02.frag", GL_FRAGMENT_SHADER);
		if (m_shaders[1]->CompileShaders(shaders) && m_shaders[1]->LinkProgram()) {
			shaders.clear();
		}
	}

	void TestTriangle_01_03::SetupVertexArray() {
		LOG_SCOPE(__FUNCTION__);
		m_pVA = std::make_unique<VertexArray>(2);
	}

	void TestTriangle_01_03::SetupVertexBuffer() {
		LOG_SCOPE(__FUNCTION__);
		std::vector<float> triangle_01{
			-0.75f, -0.25f, 0.0f, // 0
			-0.25f, -0.25f, 0.0f, // 1
			-0.5f ,  0.25f, 0.0f  // 2		
		};
		m_VBs.push_back(std::make_unique<VertexBuffer>(
			reinterpret_cast<const void*>(triangle_01.data()),
			static_cast<unsigned int>(triangle_01.size() * sizeof(GLfloat))));
		m_VBs[0]->SetVertexCount(3);
		std::vector<float> triangle_02{
			 0.25f, -0.25f, 0.0f, // 0
			 0.75f, -0.25f, 0.0f, // 1
			 0.5f ,  0.25f, 0.0f  // 2		
		};
		m_VBs.push_back(std::make_unique<VertexBuffer>(
			reinterpret_cast<const void*>(triangle_02.data()),
			static_cast<unsigned int>(triangle_02.size() * sizeof(GLfloat))));
		m_VBs[1]->SetVertexCount(3);
	}

	void TestTriangle_01_03::SetupLayout()
	{
		LOG_SCOPE(__FUNCTION__);
		m_layouts.push_back(std::make_unique<VertexBufferLayout>());
		m_layouts.push_back(std::make_unique<VertexBufferLayout>());
		m_layouts[0]->Push<float>(3);
		m_pVA->AddBuffer(0, *m_VBs[0], *m_layouts[0]);

		m_layouts[1]->Push<float>(3);
		m_pVA->AddBuffer(1, *m_VBs[1], *m_layouts[1]);
	}

	void TestTriangle_01_03::SetupRenderer() {
		m_pRenderer = std::make_unique<Renderer>();
		m_pRenderer->SetClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	}

	TestTriangle_01_03::TestTriangle_01_03()
		: m_pVA{ nullptr }
	{
		LOG_SCOPE(__FUNCTION__);

	}

	TestTriangle_01_03::~TestTriangle_01_03()
	{
		LOG_SCOPE(__FUNCTION__);

	}

	void TestTriangle_01_03::OnInitialize()
	{
		LOG_SCOPE(__FUNCTION__);
		SetupVertexArray();
		SetupVertexBuffer();
		SetupLayout();
		SetupShaders();
		SetupRenderer();
	}

	void TestTriangle_01_03::OnUpdate(float delta_time)
	{

	}

	void TestTriangle_01_03::OnRender()
	{
		m_pRenderer->Draw(*m_pVA, *(m_VBs[0]), *(m_shaders[0]));
	}

	//void TestTriangle_01_03::OnImGuiRender()
	//{

	//}

}


