#ifndef __CORE_H__
#define __CORE_H__

#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "logger.h"

#if _DEBUG
#define ASSERT(x) if (!(x)) __debugbreak();
#define GLCall(x) GLClearError(); x; ASSERT(GLLogCall(#x, __FILE__, __LINE__))
#else
#define ASSERT(x) 
#define GLCall(x) 
#endif

void GLClearError();
bool GLLogCall(const char* function, const char* file, int line);
void glfw_error_callback(int error, const char* description);

#endif __CORE_H__