#ifndef __TEST_CLEAR_COLOR_H__
#define __TEST_CLEAR_COLOR_H__

#include "test.h"

namespace Test {
	class TestClearColor : public TestBase{
		float m_clearColor[4];
	public:
		TestClearColor();
		virtual ~TestClearColor();
		
		void OnUpdate(float delta_time) override;
		void OnRender() override;
		void OnImGuiRender() override;
	};
}


#endif // __TEST_CLEAR_COLOR_H__