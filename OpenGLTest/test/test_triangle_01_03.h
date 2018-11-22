#ifndef __TEST_TRIANGLE_01_03_H__
#define __TEST_TRIANGLE_01_03_H__

#include "test.h"

namespace Test {
	class TestTriangle_01_03 : public TestBase {
	protected:
	public:
		TestTriangle_01_03();
		virtual ~TestTriangle_01_03();


		virtual void OnInitialize();

		virtual void OnUpdate(float delta_time);
		virtual void OnRender();
		virtual void OnImGuiRender();
	};
}

#endif // __TEST_TRIANGLE_01_03_H__