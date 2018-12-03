#ifndef __TEST_BLEND_H__
#define __TEST_BLEND_H__

#include "test.h"
#include "glm.hpp"

#include "renderer.h"
#include "index_buffer.h"
#include "vertex_array.h"
#include "vertex_buffer.h"
#include "shader_program.h"
#include "vertex_buffer_layout.h"

namespace Test {
    class TestBlend : public BaseTest{
            std::unique_ptr<VertexArray>          m_pVA;
            std::unique_ptr<VertexBuffer>         m_pVB;
            std::unique_ptr<IndexBuffer>          m_pIB;
            std::unique_ptr<VertexBufferLayout>   m_pLayout;
            std::unique_ptr<ShaderProgram>        m_pShader;
            std::unique_ptr<Renderer>             m_pRenderer;

            void LoadVertexData(std::vector<GLfloat>& vertices);
            void LoadIndexData(std::vector<GLuint>& indeices);

            void SetupVertexArray();
            void SetupVertexBuffer();
            void SetupIndexBuffer();
            void SetupLayout();
            void SetupShaders();
            void SetupRenderer();
        public:
            TestBlend();
            virtual ~TestBlend();

            virtual void OnInitialize();
            virtual void OnRender();
            virtual void OnUpdate(float delta);
            virtual void OnImguiRender();
    };
}

#endif // __TEST_BLEND_H__