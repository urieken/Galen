#ifndef __TEST_POLYGON_01_02_H__
#define __TEST_POLYGON_01_02_H__

#include "test_polygon_01_01.h"

namespace Test {
	class TestPolygon_01_02 : public TestPolygon_01_01 {
	protected:
		float m_deltaTime;
		virtual void SetupShaders();
	public:
		TestPolygon_01_02();
		virtual ~TestPolygon_01_02();

		virtual void OnInitialize();
		virtual void OnUpdate(float delta_time);
	};
}

#endif // __TEST_POLYGON_01_02_H__