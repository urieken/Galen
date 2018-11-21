
#include "test.h"

namespace Test
{
	TestBase::TestBase()
	{
	
	}
	
	TestBase::~TestBase()
	{
	
	}

	void TestBase::OnInitialize()
	{
		LOG_SCOPE(__FUNCTION__);
	}
	
	void TestBase::OnUpdate(float delta_time)
	{
		(void)(delta_time);
	}
	
	void TestBase::OnRender()
	{
	
	}
	
	void TestBase::OnImGuiRender()
	{
	}
	
}
