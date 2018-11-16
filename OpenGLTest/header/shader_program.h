#ifndef __SHADER_PROGRAM_H__
#define __SHADER_PROGRAM_H__

#include "core.h"

#include <map>

typedef std::map<std::string, unsigned int> shader_map;
template<typename T1, typename T2, typename T3>
constexpr auto insert_shader(T1& a, T2 b, T3 c) {
	return a.insert(std::make_pair(b, c));
}

class ShaderProgram {
public:
	ShaderProgram();
	virtual ~ShaderProgram();
};

#endif // __SHADER_PROGRAM_H__