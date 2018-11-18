
#include "shader_program.h"

#include <memory>
#include <vector>

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
			::glfwSwapInterval(1);
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

				shader_map shaders;
				insert_shader(shaders, "res/shaders/test.vert", GL_VERTEX_SHADER);
				insert_shader(shaders, "res/shaders/test.frag", GL_FRAGMENT_SHADER);

				std::unique_ptr<ShaderProgram> pShaderProgram{ std::make_unique<ShaderProgram>() };
				if (pShaderProgram->CompileShaders(shaders) && pShaderProgram->LinkProgram()) {
					pShaderProgram->UseProgram();
					shaders.clear();
				}
				
				//pShaderProgram->SetUniform4f("u_Color", 0.2f, 0.3f, 0.8f, 1.0f);
				float red = 0.0f;
				float increment = 0.01f;
				/* Loop until the user closes the window */
				while (!::glfwWindowShouldClose(window))
				{
					/* Render here */
					GLCall(::glClear(GL_COLOR_BUFFER_BIT));

					if (1.0f < red) {
						increment = -0.01f;
					}
					else if (0.0f > red) {
						increment = 0.01f;
					}
					red += increment;
					pShaderProgram->SetUniform4f("u_Color", red, 0.3f, 0.8f, 1.0f);
					GLCall(::glDrawArrays(GL_TRIANGLES, 0, 3));

					/* Swap front and back buffers */
					::glfwSwapBuffers(window);

					/* Poll for and process events */
					::glfwPollEvents();
				}
				::glBindBuffer(GL_ARRAY_BUFFER, 0);
				::glDeleteBuffers(1, &buffer);
				::glfwTerminate();
			}
			else {
				LOG_ERROR("FAILED TO INITIALIZE GLEW");
			}
		}
	}
	return nReturn;
}