#ifndef __ENTRY_POINT_H__
#define __ENTRY_POINT_H__

#ifdef GALEN_PLATFORM_WINDOWS

extern Galen::Application* Galen::CreateApplication();

int main(int argc, char** argv) {
	Galen::Application* pApplication{ Galen::CreateApplication() };
	if (nullptr != pApplication) {
		pApplication->Run();
		delete pApplication;
	}
}

#endif

#endif // __ENTRY_POINT_H__