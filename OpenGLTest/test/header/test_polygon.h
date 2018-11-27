#ifndef __TEST_POLYGON_H__
#define __TEST_POLYGON_H__

#include "glm.hpp"
#include "test.h"

#include "renderer.h"
#include "vertex_array.h"
#include "vertex_buffer.h"
#include "shader_program.h"
#include "vertex_buffer_layout.h"

namespace Test {
    class TestPolygon : public BaseTest{
        protected:
            std::unique_ptr<VertexArray>        m_pVA;
            std::unique_ptr<VertexBuffer>       m_pVB;
            std::unique_ptr<VertexBufferLayout> m_pLayout;
            std::unique_ptr<ShaderProgram>      m_pShader;
            std::unique_ptr<Renderer>           m_pRenderer;

            int                                 m_mode;
            int                                 m_newMode;
            glm::vec4                           m_color;

            virtual void SetupVertexArray();
            virtual void SetupVertexBuffer();
            virtual void SetupLayout();
            virtual void SetupShaders();
            virtual void SetupRenderer();

        public:
            TestPolygon();
            virtual ~TestPolygon();

            virtual void OnInitialize();
            virtual void OnRender();
            virtual void OnUpdate(float delta);
            virtual void OnImGuiRender();
    };
}

#endif // __TEST_POLYGON_H__