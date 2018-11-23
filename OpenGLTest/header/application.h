#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "core.h"
#include "test_list.h"

#include <string>

class Application {
	GLFWwindow* m_pWindow;
	
	bool CreateWindow();

	void RegisterTests(Test::TestMenu* pTest);

	bool ShowBackButton();
	void ShowMainMenuBar();

public:

	Application();
	virtual ~Application();
	   
	bool Initialize();
	int Run();
};

#endif // __APPLICATION_H__