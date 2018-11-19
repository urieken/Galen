#include "texture.h"
#include "shader_program.h"

#include <memory>
#include <vector>

#include "application.h"
#include "index_buffer.h"
#include "vertex_array.h"
#include "vertex_buffer.h"

int main(int argc, char** argv) {
	int nReturn{ 0 };
	
	Logger::Instance().Initialize();

	LOG_SCOPE(__FUNCTION__);
	LOG_INFO("ARGUMENT COUNT : %d", argc);
	LOG_INFO("PROGRAM NAME   : %s", argv[0]);
	if (false) {
		std::unique_ptr<Application> pApplication{std::make_unique<Application>()};
		if (nullptr != pApplication) {
			if (pApplication->Initialize())
				nReturn = pApplication->Run();
		}
		else { LOG_FATAL("FAILED TO CREATE APPLICATION OBJECT"); }
	}
	else {
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
				/* Make the window's context current */
				::glfwMakeContextCurrent(window);

				::glfwSwapInterval(1);

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

					std::unique_ptr<VertexArray> vertexArray{
						std::make_unique<VertexArray>()
					};

					std::unique_ptr<VertexBuffer> vertexBuffer{
						std::make_unique<VertexBuffer>(
							reinterpret_cast<const void*>(vertices.data()), 
							static_cast<unsigned int>(vertices.size() * sizeof(float)))};

					std::unique_ptr<VertexBufferLayout> layout{
						std::make_unique<VertexBufferLayout>()};
					layout->Push<float>(2);
					vertexArray->AddBuffer(*vertexBuffer.get(), *layout.get());

					std::unique_ptr<IndexBuffer> indexBuffer{
						std::make_unique<IndexBuffer>(
							reinterpret_cast<const unsigned int*>(indices.data()), 
							static_cast<unsigned int>(indices.size() * 2)) };

					shader_map shaders;
					insert_shader(shaders, "res/shaders/test.vert", GL_VERTEX_SHADER);
					insert_shader(shaders, "res/shaders/test.frag", GL_FRAGMENT_SHADER);

					std::unique_ptr<ShaderProgram> pShaderProgram{ std::make_unique<ShaderProgram>() };
					if (pShaderProgram->CompileShaders(shaders) && pShaderProgram->LinkProgram()) {
						pShaderProgram->Bind();
						shaders.clear();
					}
					
					pShaderProgram->UnBind();
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

						pShaderProgram->Bind();
						pShaderProgram->SetUniform4f("u_Color", red, 0.3f, 0.8f, 1.0f);
						vertexBuffer->Bind();

						vertexArray->Bind();
						indexBuffer->Bind();

						//GLCall(::glDrawArrays(GL_TRIANGLES, 0, 3));
						GLCall(::glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0));

						/* Swap front and back buffers */
						::glfwSwapBuffers(window);

						/* Poll for and process events */
						::glfwPollEvents();
					}
					::glBindBuffer(GL_ARRAY_BUFFER, 0);
					//::glDeleteBuffers(1, &buffer);
					::glfwTerminate();
				}
				else {
					LOG_ERROR("FAILED TO INITIALIZE GLEW");
				}
			}
		}
	}
	return nReturn;
}