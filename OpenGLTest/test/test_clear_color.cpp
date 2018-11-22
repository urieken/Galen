#include "test_clear_color.h"

#include "core.h"
#include "imgui.h"

namespace Test
{
	ClearColor::ClearColor()
		: m_clearColor{0.0f, 0.0f, 0.0f, 1.0f}
	{
	
	}
	
	ClearColor::~ClearColor()
	{
	
	}
	
	void ClearColor::OnUpdate(float delta_time)
	{
	
	}
	
	void ClearColor::OnRender()
	{
		GLCall(::glClearColor(m_clearColor[0], m_clearColor[1], m_clearColor[2], m_clearColor[3]));
		GLCall(::glClear(GL_COLOR_BUFFER_BIT));
	}
	
	void ClearColor::OnImGuiRender()
	{
		ImGui::ColorEdit3("Clear Color", m_clearColor);
	}
}
