#ifndef __SHADER_PROGRAM_H__
#define __SHADER_PROGRAM_H__

#include "core.h"

#include <map>
#include <vector>
#include <unordered_map>

#include "glm.hpp"

typedef std::map<std::string, unsigned int> shader_map;
template<typename T1, typename T2, typename T3>
constexpr auto insert_shader(T1& a, T2 b, T3 c) {
	return a.insert(std::make_pair(b, c));
}

class ShaderProgram {
	unsigned int m_shaderProgram;
	std::vector<unsigned int> m_shaderObjects;
	std::unordered_map<std::string, int> m_uniforms;
	bool LoadShaderSource(const std::string& filename, std::string& source);
public:
	ShaderProgram();
	virtual ~ShaderProgram();
	
	bool CompileShaders(shader_map& shaders);
	bool LinkProgram();
	void Bind() const;
	void UnBind() const;

	int GetAttributeLocation(const std::string& name);
	void SetAttributeLocation(const std::string& name, int index);

	int GetUniformLocation(const std::string& name);

	void SetUniform1i(int location, int i0);
	void SetUniform1i(const std::string& name, int i0);
	void SetUniform1f(int location, float f0);
	void SetUniform1f(const std::string& name, float f0);
	void SetUniform3f(int location, float f0, float f1, float f2);
	void SetUniform3f(const std::string& name, float f0, float f1, float f2);
	void SetUniform4f(int location, float f0, float f1, float f2, float f3);
	void SetUniform4f(const std::string& name, float f0, float f1, float f2, float f3);
	void SetUniformMat4f(int location, const float* pData);
	void SetUniformMat4f(const std::string& name, const float* pData);
	void SetUniform3fv(int location, const float* pData);
	void SetUniform3fv(const std::string& name, const float* pData);
	void SetUniform4fv(int location, const float* pData);
	void SetUniform4fv(const std::string& name, const float* pData);

};

#endif // __SHADER_PROGRAM_H__