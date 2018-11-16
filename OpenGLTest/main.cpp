#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "logger.h"

#include <vector>

#define ASSERT(x) if (!(x)) __debugbreak();
#define GLCall(x) GLClearError(); x; ASSERT(GLLogCall(#x, __FILE__, __LINE__))

static void GLClearError() {
	while (::glGetError() != GL_NO_ERROR);
}

static bool GLLogCall(const char* function, const char* file, int line) {
	while (GLenum error = ::glGetError()) {
		LOG_ERROR("OpenGL Error : %d : %s : %s : %d ", error, function, file , line);
		return false;
	}
	return true;
}

void glfw_error_callback(int error, const char* description) {
	LOG_SCOPE(__FUNCTION__);
	LOG_ERROR("ERROR OCCURED : %d [%s]", error, description);
}

int main(int argc, char** argv) {
	int nReturn{ 0 };

	Logger::Instance().Initialize();

	LOG_SCOPE(__FUNCTION__);
	LOG_INFO("ARGUMENT COUNT : %d", argc);
	LOG_INFO("PROGRAM NAME   : %s", argv[0]);

	GLFWwindow* window;

	/* Initialize the library */
	if (GLFW_FALSE == ::glfwInit()) {
		LOG_FATAL("FAILED TO INITIALIZE GLFW");
		nReturn = -1;
	}
	else {
		LOG_INFO("GLFW INITIALIZED");
		::glfwSetErrorCallback(glfw_error_callback);
		/* Create a windowed mode window and its OpenGL context */
		window = ::glfwCreateWindow(640, 480, "Hello World", nullptr, nullptr);
		if (!window)
		{
			LOG_FATAL("FAILED TO CREATE WINDOW");
			::glfwTerminate();
			nReturn = -1;
		}
		else {
			LOG_INFO("WINDOW CREATED");
			/* Make the window's context current */
			::glfwMakeContextCurrent(window);
			if (GLEW_OK == ::glewInit()) {
				LOG_INFO("GLEW INITIALIZED");
				LOG_INFO("OPENGL VERSION  : %s", ::glGetString(GL_VERSION));

				std::vector<float> vertices = 
				{
					-0.5f, -0.5f,
					 0.0f,  0.5f,
					 0.5f, -0.5f
				};

				unsigned int buffer;

				GLCall(::glGenBuffers(1, &buffer));
				GLCall(::glBindBuffer(GL_ARRAY_BUFFER, buffer));
				GLCall(::glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW));

				GLCall(::glEnableVertexAttribArray(0));
				GLCall(::glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0));

				GLCall(::glBindBuffer(GL_ARRAY_BUFFER, 0));

				/* Loop until the user closes the window */
				while (!::glfwWindowShouldClose(window))
				{
					/* Render here */
					GLCall(::glClear(GL_COLOR_BUFFER_BIT));

					GLCall(::glDrawArrays(GL_TRIANGLES, 0, 3));

					/* Swap front and back buffers */
					::glfwSwapBuffers(window);

					/* Poll for and process events */
					::glfwPollEvents();
				}
				::glfwTerminate();
			}
			else {
				LOG_ERROR("FAILED TO INITIALIZE GLEW");
			}
		}
	}
	return nReturn;
}