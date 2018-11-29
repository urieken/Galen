#include "test_interpolation.h"

namespace Test{

    Interpolation::Interpolation()
    : BaseTest{}
    , m_vao{0}
    , m_vbo{0}
    , m_pShader{nullptr}
    , m_posAttrib{0}
    , m_colAttrib{1}
    {

    }

    Interpolation::~Interpolation(){

        ::glBindVertexArray(0);
    }

    void Interpolation::OnInitialize(){
        // Create Vertex Array Object
        ::glGenVertexArrays(1, &m_vao);
        ::glBindVertexArray(m_vao);

        // Create Vertex Buffer Object
        ::glGenBuffers(1, &m_vbo);
        std::vector<GLfloat> vertices{
             0.0f,  0.5f,  1.0f,  0.0f,  0.0f,
             0.5f, -0.5f,  0.0f,  1.0f,  0.0f,
            -0.5f, -0.5f,  0.0f,  0.0f,  1.0f
        };
        ::glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
        ::glBufferData(GL_ARRAY_BUFFER, 
                       vertices.size() * sizeof(GLfloat),
                       vertices.data(), GL_STATIC_DRAW);

        // Create and compile shaders
        m_pShader.reset(new ShaderProgram{});
        shader_map shaders;

        insert_shader(shaders, "res/shaders/polygon_interpolation.vert", GL_VERTEX_SHADER);
        insert_shader(shaders, "res/shaders/polygon_interpolation.frag", GL_FRAGMENT_SHADER);

        if(m_pShader->CompileShaders(shaders) && m_pShader->LinkProgram()){
            m_pShader->Bind();
            shaders.clear();
        }

        m_posAttrib = m_pShader->GetAttributeLocation("position");
        m_colAttrib = m_pShader->GetAttributeLocation("color");
        

        LOG_INFO("POSITION ATTRIBUTE : %d", m_posAttrib);
        ::glEnableVertexAttribArray(m_posAttrib);
        ::glVertexAttribPointer(m_posAttrib, 2, GL_FLOAT, GL_FALSE, 
                                5 * sizeof(GLfloat), 0);
        LOG_INFO("COLOR ATTRIBUTE    : %d", m_colAttrib);
        ::glEnableVertexAttribArray(m_colAttrib);
        ::glVertexAttribPointer(m_colAttrib, 3, GL_FLOAT, GL_FALSE, 
                                5 * sizeof(GLfloat), (void*)(2 * sizeof(GL_FLOAT)));
    }

    void Interpolation::OnUpdate(float data){

    }

    void Interpolation::OnRender(){
        ::glClear(GL_COLOR_BUFFER_BIT);
        ::glDrawArrays(GL_TRIANGLES, 0, 3);
    }

    void Interpolation::OnImGuiRender(){

    }
}