#ifndef __TEST_H__
#define __TEST_H__

#include "core.h"

namespace Test
{
	class BaseTest {
	public:
		BaseTest();
		virtual ~BaseTest();

		virtual void OnInitialize();

		virtual void OnUpdate(float delta_time);
		virtual void OnRender();
		virtual void OnImGuiRender();
	};

}
#endif // __TEST_H__