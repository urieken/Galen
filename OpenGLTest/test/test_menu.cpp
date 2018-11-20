#include "test_menu.h"

#include "imgui.h"

namespace Test{

	TestMenu::TestMenu(TestBase*& pCurrentTest)
		: m_pCurrentTest{pCurrentTest}
	{
	
	}
	
	void TestMenu::OnImGuiRender()
	{
		for (std::pair<std::string, std::function<TestBase*()>>& test : m_tests) {
			if (ImGui::Button(test.first.c_str())) {
				m_pCurrentTest = test.second();
			}
		}
	}
}
