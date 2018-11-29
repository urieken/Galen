#ifndef __TEST_INTERPOLATION_H__
#define __TEST_INTERPOLATION_H__

#include "test.h"
#include "shader_program.h"

namespace Test {
    class Interpolation : public BaseTest{
        GLuint                         m_vao;
        GLuint                         m_vbo;
        std::unique_ptr<ShaderProgram> m_pShader;
        public: 
            Interpolation();
            virtual ~Interpolation();

            virtual void OnInitialize();

            virtual void OnUpdate(float data);
            virtual void OnRender();
            virtual void OnImGuiRender();
    };
}

#endif // __TEST_INTERPOLATION_H__