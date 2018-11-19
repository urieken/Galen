#include "application.h"

#include "logger.h"



#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

Application::Application() 
	: m_pWindow{ nullptr }
	, m_pShader{ nullptr }
	, m_pVA{ nullptr }
	, m_pVB{ nullptr }
	, m_pLayout{ nullptr }
	, m_pIB{ nullptr }
	, m_pRenderer{ nullptr }
	, m_pTexture{ nullptr }
{
	LOG_SCOPE(__FUNCTION__);
}

Application::~Application()
{
	LOG_SCOPE(__FUNCTION__);
}

// Private

bool Application::CreateWindow()
{
	bool bSuccess{ true };
	LOG_SCOPE(__FUNCTION__);
	//m_pWindow = ::glfwCreateWindow(640, 480, "Hello World", nullptr, nullptr);
	m_pWindow = ::glfwCreateWindow(1280, 720, "Hello World", nullptr, nullptr);
	if ((bSuccess = (nullptr != m_pWindow))) {
		LOG_INFO("GLFW WINDOW CREATED");

		::glfwMakeContextCurrent(m_pWindow);
		::glfwSwapInterval(1);

		GLCall(::glEnable(GL_BLEND));
		GLCall(::glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));

		if ((bSuccess = (GLEW_OK == ::glewInit()))) {
			LOG_INFO("GLEW INITIALIZED");
		}
		else {
			LOG_ERROR("FAILED TO INITIALIZE GLEW");
		}
	}
	else { 
		LOG_FATAL("FAILED TO CREATE WINDOW"); 
		::glfwTerminate();
	}
	return bSuccess;
}

void Application::InitializeImGui()
{
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;

	ImGui_ImplGlfw_InitForOpenGL(m_pWindow, true);
	ImGui_ImplOpenGL3_Init("#version 130");
	ImGui::StyleColorsDark();
}

void Application::CreateImGuiFrame()
{
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();

}

void Application::DrawImGui(glm::vec3& trans_a, glm::vec3& trans_b, ImVec4& clear_color)
{
	ImGui::Begin("Hello, world!");

	ImGui::SliderFloat3("Translation A", &trans_a.x, -1.0f, 1.0f);
	ImGui::SliderFloat3("Translation B", &trans_b.x, -1.0f, 1.0f);

	ImGui::ColorEdit3("clear color", (float*)&clear_color);
	m_pRenderer->SetClearColor(clear_color.x, clear_color.y, clear_color.z, clear_color.w);


	ImGui::Text("Application average %.3f ms/frame (%.1f FPS)",
		1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
	ImGui::End();
}

void Application::RenderImGui()
{
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void Application::DestroyImGui()
{
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
}

// Public

bool Application::Initialize()
{
	LOG_SCOPE(__FUNCTION__);
	bool bSuccess{ true };
	if ((bSuccess = (GLFW_FALSE != ::glfwInit()))) {
		LOG_INFO("GLFW INITIALIZED");

		::glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		::glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		::glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		::glfwSetErrorCallback(glfw_error_callback);

		bSuccess = CreateWindow();
	}
	else { LOG_FATAL("FAILED TO INITIALIZE GLFW"); }
	return bSuccess;
}

void Application::SetupBuffers() {
	LOG_SCOPE(__FUNCTION__);

	std::vector<float> vertices = {
		-0.5f,  0.5f, 0.0f, 1.0f,
		-0.5f, -0.5f, 0.0f, 0.0f,
		 0.5f, -0.5f, 1.0f, 0.0f,
		 0.5f,  0.5f, 1.0f, 1.0f
	};
	std::vector<unsigned int> indices = {
		0, 1, 2,
		2, 3, 0
	};

	m_pVA = std::make_unique<VertexArray>();

	m_pVB = std::make_unique<VertexBuffer>(
		reinterpret_cast<const void*>(vertices.data()),
		static_cast<unsigned int>(vertices.size() * sizeof(float)));

	m_pLayout = std::make_unique<VertexBufferLayout>();
	m_pLayout->Push<float>(2);
	m_pLayout->Push<float>(2);
	m_pVA->AddBuffer(*m_pVB.get(), *m_pLayout.get());

	m_pIB = std::make_unique<IndexBuffer>(
		reinterpret_cast<const unsigned int*>(indices.data()),
		static_cast<unsigned int>(indices.size() * 2));

	shader_map shaders;
	insert_shader(shaders, "res/shaders/test.vert", GL_VERTEX_SHADER);
	insert_shader(shaders, "res/shaders/test.frag", GL_FRAGMENT_SHADER);

	m_proj = glm::ortho(-2.0f, 2.0f, -1.5f, 1.5f, -1.0f, 1.0f );
	m_view = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, 0.0f));
	
	m_pShader = std::make_unique<ShaderProgram>();
	if (m_pShader->CompileShaders(shaders) && m_pShader->LinkProgram()) {
		m_pShader->Bind();
		shaders.clear();

		m_pTexture = std::make_unique<Texture>("res/images/cpp.png");
		m_pTexture->Bind();
		m_pShader->SetUniform1i("u_Texture", 0);
	}

	m_pVA->UnBind();
	m_pVB->UnBind();
	m_pIB->UnBind();
	m_pShader->UnBind();

	m_pRenderer = std::make_unique<Renderer>();
	InitializeImGui();
}

int Application::Run()
{
	LOG_SCOPE(__FUNCTION__);
	int nReturn{ 0 };
	LOG_INFO("OPENGL VERSION  : %s", ::glGetString(GL_VERSION));

	float red{ 0.0f };
	float increment{ 0.01f };
	glm::vec3 trans_a{  0.5f,  0.0f,  0.0f };
	glm::vec3 trans_b{ -0.5f,  0.0f,  0.0f };
	ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

	while (!::glfwWindowShouldClose(m_pWindow)) {
		
		m_pRenderer->Clear();
		CreateImGuiFrame();

		m_model = glm::translate(glm::mat4(1.0f), trans_a);
		m_model = glm::translate(glm::mat4(1.0f), trans_b);

		glm::mat4 mvp{ m_model * m_view * m_proj };

		if (1.0f < red) {
			increment = -0.01f;
		}
		else if (0.0f > red) {
			increment = 0.01f;
		}

		DrawImGui(trans_a, trans_b, clear_color);

		m_pShader->Bind();
		m_pShader->SetUniform4f("u_Color", red, 0.3f, 0.8f, 1.0f);

		{
			m_model = glm::translate(glm::mat4(1.0f), trans_a);
			glm::mat4 mvp{ m_model * m_view * m_proj };
			m_pShader->SetUniformMat4f("u_MVP", &mvp[0][0]);
			m_pRenderer->Draw(*m_pVA.get(), *m_pIB.get(), *m_pShader.get());
		}
		{
			m_model = glm::translate(glm::mat4(1.0f), trans_b);
			glm::mat4 mvp{ m_model * m_view * m_proj };
			m_pShader->SetUniformMat4f("u_MVP", &mvp[0][0]);
			m_pRenderer->Draw(*m_pVA.get(), *m_pIB.get(), *m_pShader.get());
		}

		RenderImGui();
		
		::glfwSwapBuffers(m_pWindow);
		::glfwPollEvents();
	}

	DestroyImGui();

	::glfwTerminate();
	return nReturn;
}