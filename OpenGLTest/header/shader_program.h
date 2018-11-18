#ifndef __SHADER_PROGRAM_H__
#define __SHADER_PROGRAM_H__

#include "core.h"

#include <map>
#include <vector>

typedef std::map<std::string, unsigned int> shader_map;
template<typename T1, typename T2, typename T3>
constexpr auto insert_shader(T1& a, T2 b, T3 c) {
	return a.insert(std::make_pair(b, c));
}

class ShaderProgram {
	unsigned int m_shaderProgram;
	std::vector<unsigned int> m_shaderObjects;

	bool LoadShaderSource(const std::string& filename, std::string& source);
public:
	ShaderProgram();
	virtual ~ShaderProgram();
	
	bool CompileShaders(shader_map& shaders);
	bool LinkProgram();
	void UseProgram();
	void UnuseProgram();

	unsigned int GetUniformLocation(const std::string& name);

	void SetUniform1i(unsigned int location, int i0);
	void SetUniform1i(const std::string& name, int i0);
	void SetUniform4f(unsigned int location, float f0, float f1, float f2, float f3);
	void SetUniform4f(const std::string& name, float f0, float f1, float f2, float f3);
};

#endif // __SHADER_PROGRAM_H__