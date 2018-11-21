#include "test.h"

#include "renderer.h"
#include "vertex_array.h"
#include "vertex_buffer.h"
#include "shader_program.h"
#include "vertex_buffer_layout.h"

namespace Test {
	class TestPolygon_01_01 : public TestBase {
	protected:

		std::unique_ptr<VertexArray>           m_pVA;
		std::unique_ptr<VertexBuffer>          m_pVB;
		std::unique_ptr<VertexBufferLayout>    m_pLayout;
		std::unique_ptr<ShaderProgram>         m_pShaders;
		std::unique_ptr<Renderer>              m_pRenderer;

		virtual void SetupVertexArray();
		virtual void SetupVertexBuffer();
		virtual void SetupLayout();
		virtual void SetupShaders();
		virtual void SetupRenderer();

	public:
		TestPolygon_01_01();
		virtual ~TestPolygon_01_01();

		virtual void OnInitialize();

		virtual void OnUpdate(float delta_time);
		virtual void OnRender();
		virtual void OnImGuiRender();
	};
}