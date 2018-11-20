#include "application.h"

int main(int argc, char** argv) {
	int nReturn{ 0 };

	Logger::Instance().Initialize();

	LOG_SCOPE(__FUNCTION__);
	LOG_INFO("ARGUMENT COUNT : %d", argc);
	LOG_INFO("PROGRAM NAME   : %s", argv[0]);

	std::unique_ptr<Application> pApplication{ std::make_unique<Application>() };
	if (nullptr != pApplication) {
		if (pApplication->Initialize())
			nReturn = pApplication->Run();
	}
	else { LOG_FATAL("FAILED TO CREATE APPLICATION OBJECT"); }

	return nReturn;
}