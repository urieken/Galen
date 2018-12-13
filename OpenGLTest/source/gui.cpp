#include "gui.h"

#include "imgui.h"
#include "imgui_impl_glfw.h"
#include "imgui_impl_opengl3.h"

Gui::~Gui()
{

}

void Gui::Init(GLFWwindow* pWindow)
{
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;

	ImGui_ImplGlfw_InitForOpenGL(pWindow, true);
	ImGui_ImplOpenGL3_Init("#version 330");
	ImGui::StyleColorsDark();
}

void Gui::CeateFrame()
{
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplGlfw_NewFrame();
	ImGui::NewFrame();
}

void Gui::Render()
{
	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}

void Gui::Destroy()
{
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplGlfw_Shutdown();
	ImGui::DestroyContext();
}

void Gui::ToolTipMarker(const std::string& tip)
{
	ImGui::TextDisabled("(?)");
	if (ImGui::IsItemHovered()) {
		ImGui::BeginTooltip();
		ImGui::PushTextWrapPos(ImGui::GetFontSize() * 35.0f);
		ImGui::TextUnformatted(tip.c_str());
		ImGui::PopTextWrapPos();
		ImGui::EndTooltip();
	}
}

void Gui::GlobalDetails()
{
	ImGui::SetNextWindowBgAlpha(0.5f);
	ImGui::Begin("Application Details");
	ImGui::SameLine();
	ToolTipMarker("Global application details");
	ImGui::Separator();
	ImGui::TextColored({ 0.5, 1.0, 0.5, 1.0 }, 
		"FRAMES PER SECOND              : %.1f",
		ImGui::GetIO().Framerate);
	ImGui::Separator();
	ImGui::TextColored({ 0.5, 1.0, 0.5, 1.0 }, 
		"AVERAGE MILLISECONDS PER FRAME : %.3f",
		1000.0f / ImGui::GetIO().Framerate);
	ImGui::Separator();
	ImGui::End();
}
