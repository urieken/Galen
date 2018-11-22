#ifndef __TEST_TRIANGLE_01_01_H__
#define __TEST_TRIANGLE_01_01_H__

#include "test.h"

#include "renderer.h"
#include "vertex_array.h"
#include "index_buffer.h"
#include "shader_program.h"
#include "vertex_buffer_layout.h"


namespace Test {
	class TestTriangle_01_01 : public BaseTest {

	protected:		
		std::unique_ptr<VertexArray>          m_pVA;
		std::unique_ptr<VertexBuffer>         m_pVB;
		std::unique_ptr<VertexBufferLayout>   m_pLayout;
		std::unique_ptr<ShaderProgram>        m_pShader;
		std::unique_ptr<Renderer>             m_pRenderer;
		bool                                  m_bWireFrame;

		void SetupRenderer();
		virtual void SetupShaders();
		virtual void SetupVertexBuffer();
		void SetupLayout();
		

	public:
		TestTriangle_01_01();
		virtual ~TestTriangle_01_01();

		void SetupBuffers();

		virtual void OnInitialize();

		virtual void OnUpdate(float delta_time);
		virtual void OnRender();
		virtual void OnImGuiRender();
	};
}

#endif // __TEST_TRIANGLE_01_01_H__