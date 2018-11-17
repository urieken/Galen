#include "shader_program.h"

#include <fstream>
#include <streambuf>

ShaderProgram::ShaderProgram()
	: m_shaderProgram{ 0 }
{
	LOG_SCOPE(__FUNCTION__);
}

ShaderProgram::~ShaderProgram()
{
	LOG_SCOPE(__FUNCTION__);
	GLCall(::glDeleteProgram(m_shaderProgram));
}


bool ShaderProgram::LoadShaderSource(const std::string& filename, std::string& source) {
	LOG_SCOPE(__FUNCTION__);
	bool bSuccess{true};

	std::ifstream file{filename};
	if ((bSuccess = file.is_open())) {
		LOG_INFO("LOADED SHADER FILE : %s", filename.c_str());
		file.seekg(0, std::ios::end);
		source.reserve(file.tellg());
		file.seekg(0, std::ios::beg);
		source.assign((std::istreambuf_iterator<char>(file)),
			std::istreambuf_iterator<char>());
	}
	else { LOG_ERROR("FAILED TO LOAD SHADER FILE : %s", filename.c_str()); }
	return bSuccess;
}

bool ShaderProgram::CompileShaders(shader_map& shaders) {
	LOG_SCOPE(__FUNCTION__);
	bool bSuccess{ true };
	GLCall(m_shaderProgram = ::glCreateProgram());
	for (shader_map::iterator _iter = shaders.begin(); _iter != shaders.end() && bSuccess; _iter++) {
		std::string source;
		if((bSuccess = LoadShaderSource(_iter->first, source))){
			const char* src{ source.c_str() };
			unsigned int shaderObject{ 0 };

			LOG_INFO("SHADER SOURCE :\n %s", src);

			GLCall(shaderObject = ::glCreateShader(_iter->second));
			GLCall(::glShaderSource(shaderObject, 1, &src, nullptr));
			GLCall(::glCompileShader(shaderObject));

			int result{ 0 };
			GLCall(::glGetShaderiv(shaderObject, GL_COMPILE_STATUS, &result));
			if ((bSuccess = (GL_FALSE != result))) {
				LOG_INFO("COMPILED SHADER");
				GLCall(::glAttachShader(m_shaderProgram, shaderObject));
				m_shaderObjects.push_back(shaderObject);
			}
			else { 
				int length{ 0 };
				GLCall(::glGetShaderiv(shaderObject, GL_INFO_LOG_LENGTH, &length));
				char* message = reinterpret_cast<char*>(::alloca(length * sizeof(char)));
				GLCall(::glGetShaderInfoLog(shaderObject, length, &length, message));
				LOG_ERROR("FAILED TO COMPILE SHADER : %s", message);
				GLCall(::glDeleteShader(shaderObject));
			}
		}
		
	}
	return bSuccess;
}

bool ShaderProgram::LinkProgram() {
	LOG_SCOPE(__FUNCTION__);
	bool bSuccess{ true };

	GLCall(::glLinkProgram(m_shaderProgram));
	GLCall(::glValidateProgram(m_shaderProgram));

	for (std::vector<unsigned int>::iterator _iter = m_shaderObjects.begin();
		_iter != m_shaderObjects.end(); _iter++) {
		GLCall(::glDeleteShader(*_iter));
	}

	m_shaderObjects.clear();

	return bSuccess;
}

void ShaderProgram::UseProgram() {
	LOG_SCOPE(__FUNCTION__);
	GLCall(::glUseProgram(m_shaderProgram));
}