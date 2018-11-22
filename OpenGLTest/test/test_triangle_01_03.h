#ifndef __TEST_TRIANGLE_01_03_H__
#define __TEST_TRIANGLE_01_03_H__

#include "test.h"

#include "renderer.h"
#include "vertex_array.h"
#include "vertex_buffer.h"
#include "shader_program.h"
#include "vertex_buffer_layout.h"

namespace Test {
	class TestTriangle_01_03 : public TestBase {
	protected:
		std::unique_ptr<VertexArray>                     m_pVA;
		std::vector<std::unique_ptr<VertexBuffer>>       m_VBs;
		std::vector<std::unique_ptr<VertexBufferLayout>> m_layouts;
		std::vector<std::unique_ptr<ShaderProgram>>      m_shaders;
		std::unique_ptr<Renderer>                        m_pRenderer;

		virtual void SetupShaders();
		virtual void SetupVertexArray();
		virtual void SetupVertexBuffer();
		virtual void SetupLayout();
		virtual void SetupRenderer();
	public:
		TestTriangle_01_03();
		virtual ~TestTriangle_01_03();


		virtual void OnInitialize();

		virtual void OnUpdate(float delta_time);
		virtual void OnRender();
		//virtual void OnImGuiRender();
	};
}

#endif // __TEST_TRIANGLE_01_03_H__