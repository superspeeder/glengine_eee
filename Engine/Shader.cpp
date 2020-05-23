#include "Shader.h"
#include <iostream>

Shader::Shader(std::string filepath, unsigned int type) {
	m_ShaderID = glCreateShader(type);

	std::string source = readFileContextsToString(filepath);
	const char* c_str = source.c_str();
	glShaderSource(m_ShaderID, 1, &c_str, NULL);
	glCompileShader(m_ShaderID);

	// Check for success

	int  success;
	char infoLog[512];
	glGetShaderiv(m_ShaderID, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(m_ShaderID, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::" << filepath << "::COMPILATION_FAILED\n" << infoLog << std::endl;
	}
}

Shader::~Shader() {
	glDeleteShader(m_ShaderID);
}

void Shader::AttachToProgram(unsigned int programID) {
	glAttachShader(programID, m_ShaderID);
}

void Shader::DetatchFromProgram(unsigned int programID) {
	glDetachShader(programID, m_ShaderID);

}