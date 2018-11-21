#include "core.h"
#include "string"

void GLClearError() {
	while (::glGetError() != GL_NO_ERROR);
}

bool GLLogCall(const char* function, const char* file, int line) {
	GLenum error;
	while (error = ::glGetError()) {
		std::string errorString{ "" };
		switch (error) {
		case GL_INVALID_ENUM: errorString = "GL_INVALID_ENUM"; break;
		case GL_INVALID_VALUE: errorString = "GL_INVALID_VALUE"; break;
		case GL_INVALID_OPERATION: errorString = "GL_INVALID_OPERATION"; break;
		case GL_STACK_OVERFLOW: errorString = "GL_STACK_OVERFLOW"; break;
		case GL_STACK_UNDERFLOW: errorString = "GL_STACK_UNDERFLOW"; break;
		case GL_OUT_OF_MEMORY: errorString = "GL_OUT_OF_MEMORY"; break;
		case GL_INVALID_FRAMEBUFFER_OPERATION: errorString = "GL_INVALID_FRAMEBUFFER_OPERATION"; break;
		}
		LOG_ERROR("OpenGL Error : %d(0x%xH) [%s] : %s : %s : %d ", 
			error, error, errorString.c_str(), function, file, line);
		return false;
	}
	return true;
}

void glfw_error_callback(int error, const char* description) {
	LOG_SCOPE(__FUNCTION__);
	LOG_ERROR("ERROR OCCURED : %d(%x) [%s]", error, error, description);
}