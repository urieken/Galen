#ifndef __TEST_H__
#define __TEST_H__

#include "core.h"

namespace Test
{
	class TestBase {
	public:
		TestBase();
		virtual ~TestBase();

		virtual void OnUpdate(float delta_time);
		virtual void OnRender();
		virtual void OnImGuiRender();
	};

}
#endif // __TEST_H__