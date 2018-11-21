#ifndef __TEST_POLYGON_01_02_H__
#define __TEST_POLYGON_01_02_H__

#include "test_polygon_01_01.h"

#include <chrono>

namespace Test {
	class TestPolygon_01_02 : public TestPolygon_01_01 {
	protected:
		std::chrono::time_point<std::chrono::steady_clock> m_timeStart;

		virtual void SetupShaders();
	public:
		TestPolygon_01_02();
		virtual ~TestPolygon_01_02();

		virtual void OnInitialize();
		virtual void OnUpdate(float delta_time);
	};
}

#endif // __TEST_POLYGON_01_02_H__