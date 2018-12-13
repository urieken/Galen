#include "test_blend.h"

#include "imgui.h"

namespace Test{
    TestBlend::TestBlend()
    : m_pVA{nullptr}
    , m_pVB{nullptr}
    , m_pIB{nullptr}
    , m_pLayout{nullptr}
    , m_pShader{nullptr}
    , m_pRenderer{nullptr}
    {
        LOG_SCOPE(__FUNCTION__);
    }

    TestBlend::~TestBlend(){
        LOG_SCOPE(__FUNCTION__);
    }

    void TestBlend::LoadVertexData(std::vector<GLfloat>& vertices)
    {
        LOG_SCOPE(__FUNCTION__);

        {
            std::vector<GLfloat> temp{
                // X     Y      Z     R     G     B
                -0.5f,  0.5f,  0.0f, 1.0f, 0.0f, 0.0f,
                -0.5f, -0.5f,  0.0f, 0.0f, 1.0f, 0.0f,
                 0.5f, -0.5f,  0.0f, 0.0f, 0.0f, 1.0f,
                 0.5f,  0.5f,  0.0f, 1.0f, 1.0f, 1.0f
            };
            vertices = temp;
        }
    }

    void TestBlend::LoadIndexData(std::vector<GLuint>& indices)
    {
        LOG_SCOPE(__FUNCTION__);

        {
            std::vector<GLuint> temp{
                0, 1, 2,
                0, 2, 3
            };
            indices = temp;
        }
    }

    void TestBlend::SetupVertexArray()
    {
        LOG_SCOPE(__FUNCTION__);
        m_pVA.reset(new VertexArray());
    }

    void TestBlend::SetupVertexBuffer()
    {
        LOG_SCOPE(__FUNCTION__);
        std::vector<GLfloat> vertices;
        LoadVertexData(vertices);
        m_pVB.reset(new VertexBuffer{
            vertices.data(), 
            static_cast<unsigned int>(vertices.size() * sizeof(GLfloat))
        });
    }

    void TestBlend::SetupIndexBuffer()
    {
        LOG_SCOPE(__FUNCTION__);
        std::vector<GLuint> indices;
        LoadIndexData(indices);
        m_pIB.reset(new IndexBuffer{
            indices.data(), 
            static_cast<unsigned int>(indices.size())
        });
    }

    void TestBlend::SetupLayout()
    {
        LOG_SCOPE(__FUNCTION__);
        m_pLayout.reset(new VertexBufferLayout{});
        {
            m_pLayout->Push(3, GL_FLOAT, GL_FALSE);
            m_pLayout->Push(3, GL_FLOAT, GL_FALSE);
        }
    }

    void TestBlend::SetupShaders()
    {
        LOG_SCOPE(__FUNCTION__);
        m_pShader.reset(new ShaderProgram{});
        shader_map shaders;
        {
            insert_shader(shaders, "res/shaders/blend.vert", GL_VERTEX_SHADER);
            insert_shader(shaders, "res/shaders/blend.frag", GL_FRAGMENT_SHADER);
        }
        m_pShader->CompileShaders(shaders);
        m_pShader->SetAttributeLocation("position", 0);
        m_pShader->SetAttributeLocation("color", 1);
        m_pShader->LinkProgram();
        m_pShader->Bind();
        LOG_INFO("POSITION    : %d", m_pShader->GetAttributeLocation("position"));
        LOG_INFO("COLOR       : %d", m_pShader->GetAttributeLocation("color"));
        shaders.clear();
    }

    void TestBlend::SetupRenderer()
    {
        LOG_SCOPE(__FUNCTION__);
        m_pRenderer.reset(new Renderer{});
        m_pRenderer->SetClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    }

    void TestBlend::OnInitialize(){
        LOG_SCOPE(__FUNCTION__);

        SetupVertexArray();
        SetupVertexBuffer();
        SetupIndexBuffer();
        SetupLayout();
        
        m_pVA->AddBuffer(*m_pVB, *m_pLayout);

        SetupShaders();

        m_pVA->UnBind();
        m_pVB->UnBind();
        m_pShader->UnBind();

        SetupRenderer();
    }

    void TestBlend::OnRender(){
        m_pRenderer->Clear();
        m_pRenderer->Draw(*m_pVA, *m_pIB, *m_pShader);
    }

    void TestBlend::OnUpdate(float delta){

    }

    void TestBlend::OnImguiRender(){
        ImGui::Spacing();
        ImGui::Separator();
        ImGui::TextColored({0.0f, 1.0f, 0.0f, 1.0f}, "Blending test");
		ImGui::Separator();
		if (ImGui::CollapsingHeader("Description")) {
			ImGui::Separator();
			ImGui::BulletText("This will test multiple texture renders");
			ImGui::Separator();
        }
    }
}