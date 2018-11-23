
#include "test.h"

namespace Test
{
	BaseTest::BaseTest()
	{
	
	}
	
	BaseTest::~BaseTest()
	{
	
	}

	void BaseTest::OnInitialize()
	{
		LOG_SCOPE(__FUNCTION__);
	}
	
	void BaseTest::OnUpdate(float delta_time)
	{
		(void)(delta_time);
	}
	
	void BaseTest::OnRender()
	{
	
	}
	
	void BaseTest::OnImGuiRender()
	{
	}
	
}
