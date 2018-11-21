#include "application.h"

#include "logger.h"
#include "renderer.h"

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include "../test/test_list.h"


Application::Application() 
	: m_pWindow{ nullptr }
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
			GLCall(::glGetError());
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
		InitializeImGui();
	}
	else { LOG_FATAL("FAILED TO INITIALIZE GLFW"); }
	return bSuccess;
}

int Application::Run()
{
	LOG_SCOPE(__FUNCTION__);
	int nReturn{ 0 };
	LOG_INFO("OPENGL VERSION  : %s", ::glGetString(GL_VERSION));

	Test::TestBase* pCurrentTest = new Test::TestBase();
	Test::TestMenu* pTestMenu = new Test::TestMenu(pCurrentTest);
	pCurrentTest = pTestMenu;

	pTestMenu->RegisterTest<Test::TestClearColor>("CLEAR COLOR TEST            ");
	pTestMenu->RegisterTest<Test::TestTexture>("TEXTURE TEST                ");
	pTestMenu->RegisterTest<Test::TestTriangle_01_01>("TRIANGLE TEST 01 BASE       ");
	pTestMenu->RegisterTest<Test::TestTriangle_01_02>("TRIANGLE TEST 01 EX 01      ");

	pTestMenu->RegisterTest<Test::TestPolygon_01_01>("POLYGON TEST 01 BASE        ");
	pTestMenu->RegisterTest<Test::TestPolygon_01_02>("POLYGON TEST 01 EX 01 SHADER");

	std::unique_ptr<Renderer> pRenderer{ std::make_unique<Renderer>() };
	pRenderer->SetClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	while (!::glfwWindowShouldClose(m_pWindow)) {	
		pRenderer->Clear();
		CreateImGuiFrame();
		ImGui::SetNextWindowBgAlpha(0.5f);

		if (nullptr != pCurrentTest) {
			pCurrentTest->OnUpdate(0.0f);
			pCurrentTest->OnRender();
			ImGui::Begin("TEST");
			if ((pCurrentTest != pTestMenu) && (ImGui::Button("BACK"))) {
				delete pCurrentTest;
				pCurrentTest = pTestMenu;
				pRenderer->SetClearColor(0.0f, 0.0f, 0.0f, 1.0f);
			}
			pCurrentTest->OnImGuiRender();
			ImGui::End();
		}

		RenderImGui();
		::glfwSwapBuffers(m_pWindow);
		::glfwPollEvents();
	}
	if(nullptr != pCurrentTest) 
		delete pCurrentTest;
	pTestMenu = nullptr;
	DestroyImGui();

	::glfwTerminate();
	return nReturn;
}