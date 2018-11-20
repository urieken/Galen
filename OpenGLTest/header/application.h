#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "core.h"

class Application {
	GLFWwindow* m_pWindow;

	bool CreateWindow();
	void InitializeImGui();
	void CreateImGuiFrame();
	void RenderImGui();
	void DestroyImGui();

public:
	Application();
	virtual ~Application();

	bool Initialize();
	int Run();
};

#endif // __APPLICATION_H__