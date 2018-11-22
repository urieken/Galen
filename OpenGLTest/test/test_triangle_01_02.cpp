#include "test_triangle_01_02.h"

namespace Test {

 	void TestTriangle_01_02::SetupVertexBuffer()
 	{
 		LOG_SCOPE(__FUNCTION__);
 		std::vector<float> vertices = {
 			-0.75f, -0.25f, 0.0f, // 0
 			-0.25f, -0.25f, 0.0f, // 1
 			-0.5f ,  0.25f, 0.0f, // 2
 			 0.25f, -0.25f, 0.0f, // 3
 			 0.75f, -0.25f, 0.0f, // 4
 			 0.5f ,  0.25f, 0.0f  // 5
 		};
 		m_pVB = std::make_unique<VertexBuffer>(
 			reinterpret_cast<const void*>(vertices.data()),
 			static_cast<unsigned int>(vertices.size() * sizeof(float)));
 		m_pVB->SetVertexCount(6);
 	}
 
 	TestTriangle_01_02::TestTriangle_01_02()
 	{
 
 	}
 
 	TestTriangle_01_02::~TestTriangle_01_02()
 	{
 
 	}
 
 	void TestTriangle_01_02::OnInitialize() {
 		LOG_SCOPE(__FUNCTION__);
 		m_pVA = std::make_unique<VertexArray>();
 		SetupVertexBuffer();
 		SetupLayout();
 		m_pVA->AddBuffer(*m_pVB, *m_pLayout);
 		SetupShaders();
 
 		m_pVA->UnBind();
 		m_pVB->UnBind();
 		m_pShader->UnBind();
 
 		SetupRenderer();
 	}
}