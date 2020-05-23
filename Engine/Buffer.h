#pragma once
#include <GL/glew.h>

enum BufferDataType {
	FLOAT, UINT, SHORT
};

#define VBO(count,data) Buffer(GL_ARRAY_BUFFER, count, data, BufferDataType::FLOAT)
#define IBO(count,data) Buffer(GL_ELEMENT_ARRAY_BUFFER, count, data, BufferDataType::UINT)
#define IBO_S(count,data) Buffer(GL_ELEMENT_ARRAY_BUFFER, count, data, BufferDataType::SHORT)

class Buffer {
private:
	unsigned int m_BufferID;
	unsigned int m_bufferTarget;
	BufferDataType m_dataType;
	unsigned int m_bufferUsage;
public:
	Buffer(unsigned int target, unsigned int count, const void* data, BufferDataType dataType);
	Buffer(unsigned int target, unsigned int count, const void* data, unsigned int usage, BufferDataType dataType);


	~Buffer();


	void Bind();
	void Unbind();

	static void BindNone(unsigned int target);



};