#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "core.h"
#include "test_list.h"

#include <string>

class Application {
	GLFWwindow* m_pWindow;
	
	bool CreateWindow();
	void InitializeImGui();
	void CreateImGuiFrame();
	void RenderImGui();
	void DestroyImGui();

	void RegisterTests(Test::TestMenu* pTest);

	bool ShowBackButton();
	void ShowMainMenuBar();
	void ShowToolTipMarker(const std::string & toolTip);
	void ShowGlobalDetails();

public:
	Application();
	virtual ~Application();



	bool Initialize();
	int Run();
};

#endif // __APPLICATION_H__