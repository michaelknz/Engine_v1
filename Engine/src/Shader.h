#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <fstream>
#include <glew.h>

class Shader {
public:
	Shader(const std::string& fname);
	~Shader();
	void Bind();
	void Unbind();
	std::string Read_Shader(const std::string& fname);
	GLuint Create_Shader(const std::string& shader_text, GLuint type);
private:
	GLuint prog;
	GLuint shaders[2];
};

#endif

