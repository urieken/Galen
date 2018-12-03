#include "application.h"

#include "logger.h"
#include "renderer.h"

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

#include "gui.h"


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
	//m_pWindow = ::glfwCreateWindow(1280, 720, "Hello World", nullptr, nullptr);
	m_pWindow = ::glfwCreateWindow(1600, 900, "Hello World", nullptr, nullptr);
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

void Application::RegisterTests(Test::TestMenu* pTest) {

	pTest->RegisterTest<Test::ClearColor>("CLEAR COLOR TEST            ");
	pTest->RegisterTest<Test::TextureTest>("TEXTURE TEST                ");
	pTest->RegisterTest<Test::TestPolygon>("POLYGON TEST                ");
	pTest->RegisterTest<Test::TestBlend>("BLENDING TEST               ");
	pTest->RegisterTest<Test::Interpolation>("INTERPOLATION TEST          ");
	pTest->RegisterTest<Test::TestTriangle_01_01>("TRIANGLE TEST 01 BASE       ");
	pTest->RegisterTest<Test::TestTriangle_01_02>("TRIANGLE TEST 01 EX 01      ");
	pTest->RegisterTest<Test::TestTriangle_01_03>("TRIANGLE TEST 01 EX 02 VAOs ");


	pTest->RegisterTest<Test::TestPolygon_01_01>("POLYGON TEST 01 BASE        ");
	pTest->RegisterTest<Test::TestPolygon_01_02>("POLYGON TEST 01 EX 01 SHADER");
	pTest->RegisterTest<Test::TestPolygon_01_03>("POLYGON TEST 01 EX 03 COLORS");
}

bool Application::ShowBackButton() {
	bool bReturn{ ImGui::Button("BACK") };
	
	ImGui::SameLine();
	ImGui::TextColored({ 0.0, 1.0, 0.0, 1.0 }, "<= Back to main menu");
	
	return bReturn;
}

void Application::ShowMainMenuBar()
{
	if (ImGui::BeginMainMenuBar()) {
		if (ImGui::BeginMenu("File"))
		{
			if (ImGui::MenuItem("Exit")) {

			}
			ImGui::EndMenu();
		}
		ImGui::EndMainMenuBar();
	}
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
		Gui::Init(m_pWindow);
	}
	else { LOG_FATAL("FAILED TO INITIALIZE GLFW"); }
	return bSuccess;
}

int Application::Run()
{
	LOG_SCOPE(__FUNCTION__);
	int nReturn{ 0 };
	LOG_INFO("OPENGL VERSION  : %s", ::glGetString(GL_VERSION));

	Test::BaseTest* pCurrentTest = new Test::BaseTest();
	Test::TestMenu* pTestMenu = new Test::TestMenu(pCurrentTest);
	pCurrentTest = pTestMenu;

	RegisterTests(pTestMenu);;

	std::unique_ptr<Renderer> pRenderer{ std::make_unique<Renderer>() };
	pRenderer->SetClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	while (!::glfwWindowShouldClose(m_pWindow)) {
		pRenderer->Clear();
		Gui::CeateFrame();
		if (nullptr != pCurrentTest) {
			pCurrentTest->OnUpdate(0.0f);
			pCurrentTest->OnRender();
			//ShowMainMenuBar();
			ImGui::SetNextWindowBgAlpha(0.5f);
			ImGui::Begin("Galen's OpenGL research");
			ImGui::TextColored({ 1.0, 1.0, 0.0, 1.0 }, "C++ and Math review using OpenGL");
			ImGui::Separator();
			if ((pCurrentTest != pTestMenu) && ShowBackButton()) {
				delete pCurrentTest;
				pCurrentTest = pTestMenu;
				pRenderer->SetClearColor(0.0f, 0.0f, 0.0f, 1.0f);
			}
			if (pCurrentTest->IsMenu()) {
				ImGui::TextColored({ 0.0, 1.0, 0.0, 1.0 },
					"Click the items below to test some OpenGL techniques.");
				ImGui::Separator();
			}
			pCurrentTest->OnImGuiRender();
			ImGui::End();
		}
		Gui::GlobalDetails();
		Gui::Render();
		::glfwSwapBuffers(m_pWindow);
		::glfwPollEvents();
	}
	if(nullptr != pCurrentTest) 
		delete pCurrentTest;
	pTestMenu = nullptr;
	Gui::Destroy();
	::glfwTerminate();
	return nReturn;
}