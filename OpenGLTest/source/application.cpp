#include "application.h"

#include "logger.h"

Application::Application() 
	: m_pWindow{ nullptr }
	, m_pShaderProgram{ nullptr }
	, m_pVertexArray{ nullptr }
	, m_pVertexBuffer{ nullptr }
	, m_pVertexBufferLayout{ nullptr }
	, m_pIndexBuffer{ nullptr }
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
	m_pWindow = ::glfwCreateWindow(640, 480, "Hello World", nullptr, nullptr);
	if ((bSuccess = (nullptr != m_pWindow))) {
		LOG_INFO("GLFW WINDOW CREATED");
		::glfwMakeContextCurrent(m_pWindow);
		::glfwSwapInterval(1);
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
		-0.5f,  0.5f,
		-0.5f, -0.5f,
		 0.5f, -0.5f,
		 0.5f,  0.5f
	};
	std::vector<unsigned int> indices = {
		0, 1, 2,
		2, 3, 0
	};

	m_pVertexArray = std::make_unique<VertexArray>();

	m_pVertexBuffer = std::make_unique<VertexBuffer>(
		reinterpret_cast<const void*>(vertices.data()),
		static_cast<unsigned int>(vertices.size() * sizeof(float)));

	m_pVertexBufferLayout = std::make_unique<VertexBufferLayout>();
	m_pVertexBufferLayout->Push<float>(2);
	m_pVertexArray->AddBuffer(*m_pVertexBuffer.get(), *m_pVertexBufferLayout.get());

	m_pIndexBuffer = std::make_unique<IndexBuffer>(
		reinterpret_cast<const unsigned int*>(indices.data()),
		static_cast<unsigned int>(indices.size() * 2));

	shader_map shaders;
	insert_shader(shaders, "res/shaders/test.vert", GL_VERTEX_SHADER);
	insert_shader(shaders, "res/shaders/test.frag", GL_FRAGMENT_SHADER);

	m_pShaderProgram = std::make_unique<ShaderProgram>();
	if (m_pShaderProgram->CompileShaders(shaders) && m_pShaderProgram->LinkProgram()) {
		m_pShaderProgram->Bind();
		shaders.clear();
	}
}

int Application::Run()
{
	LOG_SCOPE(__FUNCTION__);
	int nReturn{ 0 };
	LOG_INFO("OPENGL VERSION  : %s", ::glGetString(GL_VERSION));

	float red{ 0.0f };
	float increment{ 0.01f };

	while (!::glfwWindowShouldClose(m_pWindow)) {
		GLCall(::glClear(GL_COLOR_BUFFER_BIT));

		if (1.0f < red) {
			increment = -0.01f;
		}
		else if (0.0f > red) {
			increment = 0.01f;
		}
		red += increment;

		m_pShaderProgram->Bind();
		m_pShaderProgram->SetUniform4f("u_Color", red, 0.3f, 0.8f, 1.0f);
		m_pVertexBuffer->Bind();

		m_pVertexArray->Bind();
		m_pIndexBuffer->Bind();

		GLCall(::glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0));
		::glfwSwapBuffers(m_pWindow);
		::glfwPollEvents();
	}
	::glfwTerminate();
	return nReturn;
}