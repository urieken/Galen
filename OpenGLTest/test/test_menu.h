#ifndef __TEST_MENU_H__
#define __TEST_MENU_H__

#include "test.h"

#include <vector>
#include <functional>

#include "logger.h"

namespace Test {

	class TestMenu : public TestBase {
		TestBase*& m_pCurrentTest;
		std::vector<std::pair<std::string, std::function<TestBase*()>>> m_tests;
	public:
		TestMenu(TestBase*& pCurrentTest);

		void OnImGuiRender();

		template<typename _T>
		void RegisterTest(const std::string& testName) {
			LOG_SCOPE(__FUNCTION__);
			LOG_INFO("REGISTERING TEST : %s", testName.c_str());
			m_tests.push_back(std::make_pair(testName, []() {return new _T();}));
		}

		
	};
}

#endif // __TEST_MENU_H__
