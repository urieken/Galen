#ifndef __CORE_H__
#define __CORE_H__

#ifdef GALEN_PLATFORM_WINDOWS
	#ifdef GALEN_BUILD_DLL
		#define GALEN_API __declspec(dllexport)
	#else
		#define GALEN_API __declspec(dllimport)
	#endif
#else
	#error Currently supports only Windows
#endif // GALEN_PLATFORM_WINDOWS

#endif //__CORE_H__