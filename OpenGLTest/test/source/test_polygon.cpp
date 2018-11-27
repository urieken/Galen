#include "test_polygon.h"

#include "imgui.h"

namespace Test {

    void TestPolygon::SetupVertexArray(){
        LOG_SCOPE(__FUNCTION__);
        m_pVA = std::make_unique<VertexArray>();
    }

    void TestPolygon::SetupVertexBuffer(){
        LOG_SCOPE(__FUNCTION__);
        std::vector<GLfloat> vertices{
            // X    Y
            -0.5f, -0.5f, // 0
             0.5f, -0.5f, // 1
             0.0f,  0.5f  // 2
        };
        m_pVB = std::make_unique<VertexBuffer>(
          reinterpret_cast<const GLvoid*>(vertices.data()),
          static_cast<GLuint>(vertices.size() *  sizeof(GLfloat)));
          m_pVB->SetVertexCount(3);
    }

    void TestPolygon::SetupLayout(){
        LOG_SCOPE(__FUNCTION__);
        m_pLayout = std::make_unique<VertexBufferLayout>();
        m_pLayout->Push(2, GL_FLOAT, GL_FALSE);
    }

    void TestPolygon::SetupShaders(){
        shader_map shaders;
        insert_shader(shaders, "res/shaders/polygon.vert", GL_VERTEX_SHADER);
        insert_shader(shaders, "res/shaders/polygon.frag", GL_FRAGMENT_SHADER);
        m_pShader = std::make_unique<ShaderProgram>();
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

    }
    
    void TestPolygon::OnRender()
    {
        m_pRenderer->Clear();
        m_pRenderer->Draw(*m_pVA, *m_pVB, *m_pShader);
    }

    void TestPolygon::OnImGuiRender()
    {
        ImGui::Text("Milliseconds Per Frame : %.3f", 
            1000.0f / ImGui::GetIO().Framerate);
        ImGui::Text("Frames Per Second      : %.1f",
            ImGui::GetIO().Framerate);
    }
}