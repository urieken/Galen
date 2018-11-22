#include "test_clear_color.h"

#include <array>

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
		ImGui::Text("Testing for clearing the color buffer");
		ImGui::Separator();
		ImGui::ColorEdit3("Clear Color", m_clearColor);
		ImGui::Separator();
		//ImGui::ShowTestWindow();
		std::array<int, 10> arr = { 0 };
		for (int i = 0; i < arr.size(); ++i) {
			ImGui::PushID(i);
			ImGui::InputInt("##", &arr[i]);
			ImGui::PopID();
		}
	}
}
