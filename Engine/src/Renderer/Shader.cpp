#include "Shader.h"

Shader::Shader(const std::string& fname) {
	prog = glCreateProgram();

	shaders[0] = Create_Shader(Read_Shader("src/shaders/" + fname + ".vs"), GL_VERTEX_SHADER);
	shaders[1] = Create_Shader(Read_Shader("src/shaders/" + fname + ".frag"), GL_FRAGMENT_SHADER);

	for (int i = 0; i < 2; ++i) {
		glAttachShader(prog, shaders[i]);
	}

	glLinkProgram(prog);

	GLint loglen;
	glGetProgramiv(prog, GL_INFO_LOG_LENGTH, &loglen);
	if (loglen > 0) {
		char* log = new char[loglen];
		GLsizei writen;
		glGetProgramInfoLog(prog, loglen, &writen, log);
		printf("%s\n", log);
		delete[] log;
	}
}

Shader::~Shader() {
	for (int i = 0; i < 2; ++i) {
		glDetachShader(prog, shaders[i]);
	}
	glDeleteProgram(prog);
}

std::string Shader::Read_Shader(const std::string& fname) {
	std::string out;
	std::ifstream file;
	file.open(fname.c_str());
	std::string line;
	while (file.good()) {
		std::getline(file, line);
		out.append(line + "\n");
	}
	file.close();
	return out;
}

GLuint Shader::Create_Shader(const std::string& shader_text, GLuint type) {
	GLuint Shader = glCreateShader(type);
	const GLchar* p[1];
	p[0] = shader_text.c_str();
	GLint l[1];
	glShaderSource(Shader, 1, p, l);
	glCompileShader(Shader);
	return Shader;
}

void Shader::Bind() {
	glUseProgram(prog);
}

void Shader::Unbind() {
	glUseProgram(0);
}

GLuint Shader::Get_Prog() {
	return prog;
}