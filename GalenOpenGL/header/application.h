#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "core.h"

namespace Galen {
	class GALEN_API Application {
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
}

#endif //__APPLICATION_H__