#pragma once

#include <GL\glew.h>
#include "Shader.h"
#include <string>

class ShaderProgram
{
private:
	unsigned int m_programID;
public:
	ShaderProgram();
	~ShaderProgram();

	void AttachShader(Shader* shader);
	void LinkProgram();

	void Use();
	
	unsigned int UniformLocation(std::string name);

	void Uniform1f(std::string name, float n);
	void Uniform2f(std::string name, float x, float y);
	void Uniform3f(std::string name, float x, float y, float z);
	void Uniform4f(std::string name, float x, float y, float z, float w);

	void Uniform1i(std::string name, int n);
	void Uniform2i(std::string name, int x, int y);
	void Uniform3i(std::string name, int x, int y, int z);
	void Uniform4i(std::string name, int x, int y, int z, int w);

	void Uniform1ui(std::string name, unsigned int n);
	void Uniform2ui(std::string name, unsigned int x, unsigned int y);
	void Uniform3ui(std::string name, unsigned int x, unsigned int y, unsigned int z);
	void Uniform4ui(std::string name, unsigned int x, unsigned int y, unsigned int z, unsigned int w);

	void Uniform1fv(std::string name, int count, const float* ptr);
	void Uniform2fv(std::string name, int count, const float* ptr);
	void Uniform3fv(std::string name, int count, const float* ptr);
	void Uniform4fv(std::string name, int count, const float* ptr);

	void Uniform1iv(std::string name, int count, const int* ptr);
	void Uniform2iv(std::string name, int count, const int* ptr);
	void Uniform3iv(std::string name, int count, const int* ptr);
	void Uniform4iv(std::string name, int count, const int* ptr);

	void Uniform1uiv(std::string name, int count, const unsigned int* ptr);
	void Uniform2uiv(std::string name, int count, const unsigned int* ptr);
	void Uniform3uiv(std::string name, int count, const unsigned int* ptr);
	void Uniform4uiv(std::string name, int count, const unsigned int* ptr);

	void UniformMatrix2fv(std::string name, int count, bool transpose, const float* ptr);
	void UniformMatrix3fv(std::string name, int count, bool transpose, const float* ptr);
	void UniformMatrix4fv(std::string name, int count, bool transpose, const float* ptr);
	
	void UniformMatrix2x3fv(std::string name, int count, bool transpose, const float* ptr);
	void UniformMatrix3x2fv(std::string name, int count, bool transpose, const float* ptr);
	
	void UniformMatrix2x4fv(std::string name, int count, bool transpose, const float* ptr);
	void UniformMatrix4x2fv(std::string name, int count, bool transpose, const float* ptr);
	
	void UniformMatrix3x4fv(std::string name, int count, bool transpose, const float* ptr);
	void UniformMatrix4x3fv(std::string name, int count, bool transpose, const float* ptr);


};

