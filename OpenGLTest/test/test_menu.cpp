#include "test_menu.h"

#include "imgui.h"

namespace Test{

	TestMenu::TestMenu(BaseTest*& pCurrentTest)
		: m_pCurrentTest{pCurrentTest}
	{
	
	}
	
	void TestMenu::OnImGuiRender()
	{
		for (std::pair<std::string, std::function<BaseTest*()>>& test : m_tests) {
			if (ImGui::Button(test.first.c_str())) {
				m_pCurrentTest = test.second();
				m_pCurrentTest->OnInitialize();
			}
		}
	}
}
