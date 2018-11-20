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
	class TestTriangle : public TestBase {
		std::unique_ptr<VertexArray>          m_pVA;
		std::unique_ptr<VertexBuffer>         m_pVB;
		std::unique_ptr<VertexBufferLayout>   m_pLayout;
		std::unique_ptr<IndexBuffer>          m_pIB;
		std::unique_ptr<ShaderProgram>        m_pShader;
		std::unique_ptr<Renderer>             m_pRenderer;

		void SetupRenderer();
		void SetupShaders();
		void SetupIndexBuffer();
		void SetupLayout();
		void SetupVertexBuffer();
		void SetupBuffers();

	public:
		TestTriangle();
		virtual ~TestTriangle();

		void OnUpdate(float delta_time) override;
		void OnRender() override;
		void OnImGuiRender() override;
	};
}

#endif // __TEST_TRIANGLE_H__