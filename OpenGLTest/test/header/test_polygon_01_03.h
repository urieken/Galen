#ifndef __TEST_POLYGON_01_03_H__
#define __TEST_POLYGON_01_03_H__

#include "test_polygon_01_01.h"

#include "index_buffer.h"

namespace Test {
	class TestPolygon_01_03 : public TestPolygon_01_01 {
	protected:

		std::unique_ptr<IndexBuffer> m_pIB;

		virtual void SetupVertexBuffer();
		virtual void SetupLayout();
		virtual void SetupIndexBuffer();
		virtual void SetupShaders();

	public:

		TestPolygon_01_03();
		virtual ~TestPolygon_01_03();

		virtual void OnInitialize();
		virtual void OnRender();
	};
}

#endif // __TEST_POLYGON_01_03_H__