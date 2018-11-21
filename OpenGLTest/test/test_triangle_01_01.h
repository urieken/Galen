#ifndef __TEST_TRIANGLE_H__
#define __TEST_TRIANGLE_H__

#include "test.h"

#include "renderer.h"
#include "vertex_array.h"
#include "index_buffer.h"
#include "vertex_buffer.h"
#include "shader_program.h"
#include "vertex_buffer_layout.h"


namespace Test {
	class TestTriangle_01_01 : public TestBase {
		std::unique_ptr<VertexArray>          m_pVA;
		std::unique_ptr<VertexBuffer>         m_pVB;
		std::unique_ptr<VertexBufferLayout>   m_pLayout;
		std::unique_ptr<IndexBuffer>          m_pIB;
		std::unique_ptr<ShaderProgram>        m_pShader;
		std::unique_ptr<Renderer>             m_pRenderer;

		bool                                  m_bWireFrame;

		void SetupRenderer();
		void SetupShaders();
		void SetupIndexBuffer();
		void SetupLayout();
		void SetupVertexBuffer();
		void SetupBuffers();

	public:
		TestTriangle_01_01();
		virtual ~TestTriangle_01_01();

		void OnUpdate(float delta_time) override;
		void OnRender() override;
		void OnImGuiRender() override;
	};
}

#endif // __TEST_TRIANGLE_H__