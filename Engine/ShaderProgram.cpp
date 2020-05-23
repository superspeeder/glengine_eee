#include "ShaderProgram.h"
#include <iostream>

ShaderProgram::ShaderProgram() {
	m_programID = glCreateProgram();
}

ShaderProgram::~ShaderProgram() {
	glDeleteProgram(m_programID);
}

void ShaderProgram::AttachShader(Shader* shader) {
	shader->AttachToProgram(m_programID);
}

void ShaderProgram::Use() {
	glUseProgram(m_programID);
}

void ShaderProgram::LinkProgram() {
	glLinkProgram(m_programID);

	int  success;
	char infoLog[512];

	glGetProgramiv(m_programID, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(m_programID, 512, NULL, infoLog);
		std::cout << "ERROR::PROGRAM::LINK_FAILED\n" << infoLog << std::endl;
	}
}


unsigned int ShaderProgram::UniformLocation(std::string name) {
	return glGetUniformLocation(m_programID, name.c_str());
}

void ShaderProgram::Uniform1f(std::string name, float n) {
	glUniform1f(UniformLocation(name), n);
}
void ShaderProgram::Uniform2f(std::string name, float x, float y) {
	glUniform2f(UniformLocation(name), x,y);
}
void ShaderProgram::Uniform3f(std::string name, float x, float y, float z) {
	glUniform3f(UniformLocation(name), x, y, z);
}
void ShaderProgram::Uniform4f(std::string name, float x, float y, float z, float w) {
	glUniform4f(UniformLocation(name), x, y, z, w);
}

void ShaderProgram::Uniform1i(std::string name, int n) {
	glUniform1i(UniformLocation(name), n);
}
void ShaderProgram::Uniform2i(std::string name, int x, int y) {
	glUniform2i(UniformLocation(name),x,y);
}
void ShaderProgram::Uniform3i(std::string name, int x, int y, int z) {
	glUniform3i(UniformLocation(name),x,y,z);
}
void ShaderProgram::Uniform4i(std::string name, int x, int y, int z, int w) {
	glUniform4i(UniformLocation(name),x,y,z,w);
}

void ShaderProgram::Uniform1ui(std::string name, unsigned int n) {
	glUniform1ui(UniformLocation(name),n);
}
void ShaderProgram::Uniform2ui(std::string name, unsigned int x, unsigned int y) {
	glUniform2ui(UniformLocation(name),x,y);
}
void ShaderProgram::Uniform3ui(std::string name, unsigned int x, unsigned int y, unsigned int z) {
	glUniform3ui(UniformLocation(name),x,y,z);
}
void ShaderProgram::Uniform4ui(std::string name, unsigned int x, unsigned int y, unsigned int z, unsigned int w) {
	glUniform4ui(UniformLocation(name),x,y,z,w);
}

void ShaderProgram::Uniform1fv(std::string name, int count, const float* ptr) {
	glUniform1fv(UniformLocation(name),count,ptr);
}
void ShaderProgram::Uniform2fv(std::string name, int count, const float* ptr) {
	glUniform2fv(UniformLocation(name), count, ptr);
}
void ShaderProgram::Uniform3fv(std::string name, int count, const float* ptr) {
	glUniform3fv(UniformLocation(name), count, ptr);
}
void ShaderProgram::Uniform4fv(std::string name, int count, const float* ptr) {
	glUniform4fv(UniformLocation(name), count, ptr);
}

void ShaderProgram::Uniform1iv(std::string name, int count, const int* ptr) {
	glUniform1iv(UniformLocation(name), count, ptr);
}
void ShaderProgram::Uniform2iv(std::string name, int count, const int* ptr) {
	glUniform2iv(UniformLocation(name), count, ptr);
}
void ShaderProgram::Uniform3iv(std::string name, int count, const int* ptr) {
	glUniform3iv(UniformLocation(name), count, ptr);
}
void ShaderProgram::Uniform4iv(std::string name, int count, const int* ptr) {
	glUniform4iv(UniformLocation(name), count, ptr);
}

void ShaderProgram::Uniform1uiv(std::string name, int count, const unsigned int* ptr) {
	glUniform1uiv(UniformLocation(name), count, ptr);
}
void ShaderProgram::Uniform2uiv(std::string name, int count, const unsigned int* ptr) {
	glUniform2uiv(UniformLocation(name), count, ptr);
}
void ShaderProgram::Uniform3uiv(std::string name, int count, const unsigned int* ptr) {
	glUniform3uiv(UniformLocation(name), count, ptr);
}
void ShaderProgram::Uniform4uiv(std::string name, int count, const unsigned int* ptr) {
	glUniform4uiv(UniformLocation(name), count, ptr);
}

void ShaderProgram::UniformMatrix2fv(std::string name, int count, bool transpose, const float* ptr) {
	glUniformMatrix2fv(UniformLocation(name), count, transpose, ptr);
}
void ShaderProgram::UniformMatrix3fv(std::string name, int count, bool transpose, const float* ptr) {
	glUniformMatrix3fv(UniformLocation(name), count, transpose, ptr);
}
void ShaderProgram::UniformMatrix4fv(std::string name, int count, bool transpose, const float* ptr) {
	glUniformMatrix4fv(UniformLocation(name), count, transpose, ptr);
}

void ShaderProgram::UniformMatrix2x3fv(std::string name, int count, bool transpose, const float* ptr) {
	glUniformMatrix2x3fv(UniformLocation(name), count, transpose, ptr);
}
void ShaderProgram::UniformMatrix3x2fv(std::string name, int count, bool transpose, const float* ptr) {
	glUniformMatrix3x2fv(UniformLocation(name), count, transpose, ptr);
}

void ShaderProgram::UniformMatrix2x4fv(std::string name, int count, bool transpose, const float* ptr) {
	glUniformMatrix2x4fv(UniformLocation(name), count, transpose, ptr);
}
void ShaderProgram::UniformMatrix4x2fv(std::string name, int count, bool transpose, const float* ptr) {
	glUniformMatrix4x2fv(UniformLocation(name), count, transpose, ptr);
}

void ShaderProgram::UniformMatrix3x4fv(std::string name, int count, bool transpose, const float* ptr) {
	glUniformMatrix3x4fv(UniformLocation(name), count, transpose, ptr);
}
void ShaderProgram::UniformMatrix4x3fv(std::string name, int count, bool transpose, const float* ptr) {
	glUniformMatrix4x3fv(UniformLocation(name), count, transpose, ptr);
}
