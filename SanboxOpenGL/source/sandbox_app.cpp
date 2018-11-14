#include "sandbox_app.h"


SandBoxApp::SandBoxApp()
	: Application{}
{
}

SandBoxApp::~SandBoxApp()
{

}

Galen::Application* Galen::CreateApplication() {
	return new SandBoxApp();
}