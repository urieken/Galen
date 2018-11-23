#ifndef __TEST_TRIANGLE_01_02_H__
#define __TEST_TRIANGLE_01_02_H__

#include "test_triangle_01_01.h"

namespace Test {
 	class TestTriangle_01_02 : public TestTriangle_01_01 {
 	protected:
 		virtual void SetupVertexBuffer();
 	public:
 		TestTriangle_01_02();
 		virtual ~TestTriangle_01_02();
 
 		virtual void OnInitialize();
 	};
}

#endif // __TEST_TRIANGLE_01_02_H__