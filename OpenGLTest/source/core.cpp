#include "core.h"

void GLClearError() {
	while (::glGetError() != GL_NO_ERROR);
}

bool GLLogCall(const char* function, const char* file, int line) {
	while (GLenum error = ::glGetError()) {
		LOG_ERROR("OpenGL Error : %d(0x%xH) : %s : %s : %d ", error, error, function, file, line);
		return false;
	}
	return true;
}

void glfw_error_callback(int error, const char* description) {
	LOG_SCOPE(__FUNCTION__);
	LOG_ERROR("ERROR OCCURED : %d(%x) [%s]", error, error, description);
}