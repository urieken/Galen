#include "test_polygon.h"

#include "imgui.h"
#include "gtc/matrix_transform.hpp"
#include "gtc/type_ptr.hpp"

namespace Test {

    GLuint TestPolygon::LoadVertexData(std::vector<GLfloat>& vertices){
        GLuint attributeCount{0};
        switch(m_mode){
            case 0:
            case 1:{
                std::vector<GLfloat> temp{
                    // X    Y
                    -0.5f, -0.5f, // 0
                     0.5f, -0.5f, // 1
                     0.0f,  0.5f  // 2
                };
                vertices = temp;
                attributeCount = 2;
            }break;
            case 2:{
                std::vector<GLfloat> temp{
                    // X    Y
                    -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, // 0
                     0.5f, -0.5f, 0.0f, 1.0f, 0.0f, // 1
                     0.0f,  0.5f, 1.0f, 0.0f, 0.0f, // 2
                };
                vertices = temp;
                attributeCount = 5;
            }break;
            default:{
                std::vector<GLfloat> temp{
                    // X    Y
                    -0.5f, -0.5f, // 0
                     0.5f, -0.5f, // 1
                     0.0f,  0.5f  // 2
                };
                vertices = temp;
                attributeCount = 2;
            }break;
        }
        return attributeCount;
    }

    void TestPolygon::SetupVertexArray(){
        LOG_SCOPE(__FUNCTION__);
        m_pVA = std::make_unique<VertexArray>();
    }

    void TestPolygon::SetupVertexBuffer(){
        LOG_SCOPE(__FUNCTION__);
        std::vector<GLfloat> vertices;
        GLuint attributeCount{LoadVertexData(vertices)};
        m_pVB = std::make_unique<VertexBuffer>(
          reinterpret_cast<const GLvoid*>(vertices.data()),
          static_cast<GLuint>(vertices.size() *  sizeof(GLfloat)));
        m_pVB->SetVertexCount(vertices.size() / attributeCount);
    }

    void TestPolygon::SetupLayout(){
        LOG_SCOPE(__FUNCTION__);
        m_pLayout = std::make_unique<VertexBufferLayout>();
        switch(m_mode){
            case 0:
            case 1:{
                m_pLayout->Push(2, GL_FLOAT, GL_FALSE);
            }break;
            case 2:{
                m_pLayout->Push(2, GL_FLOAT, GL_FALSE);
                m_pLayout->Push(3, GL_FLOAT, GL_FALSE);
            }break;
            default:{
                m_pLayout->Push(2, GL_FLOAT, GL_FALSE);
            }break;
        }
    }

    void TestPolygon::SetupShaders(){
        LOG_SCOPE(__FUNCTION__);
        shader_map shaders;
        switch(m_mode){
            case 0:{
                insert_shader(shaders, "res/shaders/polygon.vert", GL_VERTEX_SHADER);
                insert_shader(shaders, "res/shaders/polygon.frag", GL_FRAGMENT_SHADER);
            }break;
            case 1:{
                insert_shader(shaders, "res/shaders/polygon.vert", GL_VERTEX_SHADER);
                insert_shader(shaders, "res/shaders/polygon_uniform.frag", GL_FRAGMENT_SHADER);

            }break;
            case 2:{
                insert_shader(shaders, "res/shaders/polygon_interpolation.vert", GL_VERTEX_SHADER);
                insert_shader(shaders, "res/shaders/polygon_interpolation.frag", GL_FRAGMENT_SHADER);
            }break;
            default:{
                insert_shader(shaders, "res/shaders/polygon.vert", GL_VERTEX_SHADER);
                insert_shader(shaders, "res/shaders/polygon.frag", GL_FRAGMENT_SHADER);
            }break;
        }
        //m_pShader = std::make_unique<ShaderProgram>();
        m_pShader.reset(new ShaderProgram{});
        if(m_pShader->CompileShaders(shaders) && m_pShader->LinkProgram()){
            m_pShader->Bind();
            shaders.clear();
        }
    }

    void TestPolygon::SetupRenderer(){
        m_pRenderer = std::make_unique<Renderer>();
        m_pRenderer->SetClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    }

    TestPolygon::TestPolygon()
        : BaseTest{}
        , m_pVA{nullptr}
        , m_pVB{nullptr}
        , m_pLayout{nullptr}
        , m_pShader{nullptr}
        , m_pRenderer{nullptr}
        , m_mode{0}
        , m_color{0.0f, 0.0f, 0.0f, 1.0f}
    {

    }

    TestPolygon::~TestPolygon()
    {

    }

    void TestPolygon::OnInitialize()
    {
        SetupVertexArray();
        SetupVertexBuffer();
        SetupLayout();

        m_pVA->AddBuffer(*m_pVB, *m_pLayout);

        SetupShaders();

        m_pVA->UnBind();
        m_pVB->UnBind();
        m_pShader->UnBind();

        SetupRenderer();
    }

    void TestPolygon::OnUpdate(float delta)
    {
        if(m_mode != m_newMode){
            m_mode = m_newMode;
            m_pVA.reset(nullptr);
            m_pVB.reset(nullptr);
            m_pLayout.reset(nullptr);
            m_pShader.reset(nullptr);
            m_pRenderer.reset(nullptr);
            OnInitialize();
        }
    }
    
    void TestPolygon::OnRender()
    {
        m_pRenderer->Clear();
        m_pRenderer->Draw(*m_pVA, *m_pVB, *m_pShader);
    }

    void TestPolygon::OnImGuiRender()
    {
        ImGui::Spacing();
        if(ImGui::CollapsingHeader("Description")){
            ImGui::TextColored({0.0, 1.0, 0.0, 1.0}, "Polygon Test");
            ImGui::Separator();
            switch(m_mode){
                case 0:{
                    ImGui::BulletText("Draw a basic triangle with a pre-defined color");
                    ImGui::BulletText("The color is hard coded in the vertex shader");
                }break;
                case 1:{
                    ImGui::BulletText("Draw a basic triangle with a specified color");
                    ImGui::BulletText("Color data is sent to the shader program via uniforms");
                    ImGui::ColorEdit3("Clear Color", glm::value_ptr(m_color));
                    m_pShader->Bind();
                    m_pShader->SetUniform4fv("u_Color", glm::value_ptr(m_color));
                }break;
                case 2:{
                    ImGui::BulletText("Draw a basic triangle with interpolated color");
                    ImGui::BulletText("Color data is specified in the vertex buffer");
                    ImGui::BulletText("Color is rendered from one vertex to another via interpolation");
                }break;
                default : {
                    m_mode = 0;
                    ImGui::BulletText("Draw a basic triangle with a pre-defined color");
                    ImGui::BulletText("The color is hard coded in the vertex shader");
                }break;
            }
            ImGui::Separator();
            ImGui::RadioButton("MODE 0", &m_newMode, 0); ImGui::SameLine();
            ImGui::RadioButton("MODE 1", &m_newMode, 1); ImGui::SameLine();
            ImGui::RadioButton("MODE 2", &m_newMode, 2); 
        }
    }
}