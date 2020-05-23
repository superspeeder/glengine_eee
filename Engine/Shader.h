#pragma once

#include <GL\glew.h>
#include <string>
#include "Files.h"
	
class Shader
{
private:
	unsigned int m_ShaderID;
public:
	Shader(std::string filepath, unsigned int type);
	~Shader();

	void AttachToProgram(unsigned int programID);
	void DetatchFromProgram(unsigned int programID);
};

