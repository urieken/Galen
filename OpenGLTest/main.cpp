#include "texture.h"
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

		::glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		::glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		::glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

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

				//std::vector<float> vertices =
				//{
				//	-0.5f,  0.5f, 0.0f, 1.0f,
				//	-0.5f, -0.5f, 0.0f, 0.0f,
				//	 0.5f, -0.5f, 1.0f, 0.0f,
				//	 0.5f,  0.5f, 1.0f, 1.0f
				//};
				std::vector<float> vertices =
				{
					-0.5f,  0.5f, //0.0f, 1.0f,
					-0.5f, -0.5f, //0.0f, 0.0f,
					 0.5f, -0.5f, //1.0f, 0.0f,
					 0.5f,  0.5f  //, 1.0f, 1.0f
				};

				std::vector<unsigned int> indices = 
				{
					0, 1, 2,
					2, 3, 0
				};

				unsigned int vao;
				GLCall(::glGenVertexArrays (1, &vao));
				GLCall(::glBindVertexArray(vao));

				unsigned int buffer;

				GLCall(::glGenBuffers(1, &buffer));
				GLCall(::glBindBuffer(GL_ARRAY_BUFFER, buffer));
				GLCall(::glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(float), vertices.data(), GL_STATIC_DRAW));

				//GLCall(::glEnableVertexAttribArray(0));
				//GLCall(::glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0));
				//GLCall(::glEnableVertexAttribArray(1));
				//GLCall(::glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)2));

				unsigned int index_buffer;

				GLCall(::glGenBuffers(1, &index_buffer));
				GLCall(::glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_buffer));
				GLCall(::glBufferData(GL_ELEMENT_ARRAY_BUFFER, vertices.size() * 2 * sizeof(unsigned int),
					indices.data(), GL_STATIC_DRAW));
				
				shader_map shaders;
				insert_shader(shaders, "res/shaders/test.vert", GL_VERTEX_SHADER);
				insert_shader(shaders, "res/shaders/test.frag", GL_FRAGMENT_SHADER);

				std::unique_ptr<ShaderProgram> pShaderProgram{ std::make_unique<ShaderProgram>() };
				if (pShaderProgram->CompileShaders(shaders) && pShaderProgram->LinkProgram()) {
					pShaderProgram->UseProgram();
					shaders.clear();
				}
				
				//Texture texture{"res/images/opengl.png"};
				//texture.Bind();
				//pShaderProgram->SetUniform1i("u_Texture", 0);

				//pShaderProgram->SetUniform4f("u_Color", 0.2f, 0.3f, 0.8f, 1.0f);

				pShaderProgram->UnuseProgram();
				GLCall(::glBindBuffer(GL_ARRAY_BUFFER, 0));
				GLCall(::glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
				
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

					pShaderProgram->UseProgram();
					pShaderProgram->SetUniform4f("u_Color", red, 0.3f, 0.8f, 1.0f);
					GLCall(::glBindBuffer(GL_ARRAY_BUFFER, buffer));

					GLCall(::glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_buffer));

					GLCall(::glEnableVertexAttribArray(0));
					GLCall(::glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0));

					//GLCall(::glDrawArrays(GL_TRIANGLES, 0, 3));
					GLCall(::glDrawElements(GL_TRIANGLES, 6 , GL_UNSIGNED_INT, 0));

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