#ifndef __GUI_H__
#define __GUI_H__

#include "core.h"

class Gui {
	Gui() {}
	Gui(const Gui& other) {}
	const Gui& operator = (const Gui& other) {}
public:
	virtual ~Gui();

	static void Init(GLFWwindow* pWindow);
	static void CeateFrame();
	static void Render();
	static void Destroy();


	static void ToolTipMarker(const std::string& tip);
	static void GlobalDetails();
};


#endif // __GUI_H__