#include "test_interpolation.h"

namespace Test{

    Interpolation::Interpolation()
    : BaseTest{}
    , m_vao{0}
    , m_vbo{0}
    , m_pShader{nullptr}
    {

    }

    Interpolation::~Interpolation(){

        ::glBindVertexArray(0);
    }

    void Interpolation::OnInitialize(){
        // Create Vertex Array Object
        ::glGetVertexArrays(1, &m_vao);
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
        

    }

    void Interpolation::OnUpdate(float data){

    }

    void Interpolation::OnRender(){

    }

    void Interpolation::OnImGuiRender(){

    }
}