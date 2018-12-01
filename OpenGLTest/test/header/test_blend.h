#ifndef __TEST_BLEND_H__
#define __TEST_BLEND_H__

#include "test.h"
#include "glm.hpp"

namespace Test {
    class TestBlend : public BaseTest{
        public:
            TestBlend();
            virtual ~TestBlend();

            virtual void OnInitialize();
            virtual void OnRender();
            virtual void OnUpdate(float delta);
            virtual void OnImguiRender();
    };
}

#endif // __TEST_BLEND_H__