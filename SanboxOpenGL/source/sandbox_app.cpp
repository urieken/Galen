#include "sandbox_app.h"

#include "logger.h"

SandBoxApp::SandBoxApp()
	: Application{}
{
	LOG_SCOPE(__FUNCTION__);
}

SandBoxApp::~SandBoxApp()
{
	LOG_SCOPE(__FUNCTION__);
}

Galen::Application* Galen::CreateApplication() {
	LOG_SCOPE(__FUNCTION__);
	return new SandBoxApp();
}