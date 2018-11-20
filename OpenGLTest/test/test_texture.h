#ifndef __TEST_TEXTURE_H__
#define __TEST_TEXTURE_H__

#include "test.h"

#include "glm.hpp"
#include "imgui.h"

#include "texture.h"
#include "renderer.h"
#include "index_buffer.h"
#include "vertex_array.h"
#include "vertex_buffer.h"
#include "shader_program.h"
#include "vertex_buffer_layout.h"

namespace Test {
	class TestTexture : public TestBase {
		std::unique_ptr<ShaderProgram>      m_pShader;
		std::unique_ptr<VertexArray>        m_pVA;
		std::unique_ptr<VertexBuffer>       m_pVB;
		std::unique_ptr<VertexBufferLayout> m_pLayout;
		std::unique_ptr<IndexBuffer>        m_pIB;
		std::unique_ptr<Renderer>           m_pRenderer;
		std::unique_ptr<Texture>            m_pTexture;

		glm::mat4 m_proj;
		glm::mat4 m_view;
		glm::mat4 m_model;

		glm::vec3 m_trans_a;
		glm::vec3 m_trans_b;
		
		ImVec4    m_clear_color;

		float     m_red;
		float     m_increment;

		void SetupBuffers();

	public:
		TestTexture();
		virtual ~TestTexture();

		void OnUpdate(float delta_time) override;
		void OnRender() override;
		void OnImGuiRender() override;
	};
}

#endif // __TEST_TEXTURE_H__