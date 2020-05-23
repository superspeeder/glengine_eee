#pragma once

#include <GL\glew.h>

class VertexArray
{
private:
	unsigned int m_VAO_ID;
public:
	VertexArray();
	~VertexArray();
	
	void Bind();
	static void BindNone();

	void EnableAttribute(unsigned int id);
	void DisableAttribute(unsigned int id);
	
	void VertexAttribute(unsigned int index, int size, unsigned int type, bool normalized, unsigned int stride, const void* pointer);

	inline void _3D(unsigned int index, unsigned int type, unsigned int stride, const void* pointer) { Bind(); VertexAttribute(index, 3, type, false, stride, pointer); };
	inline void _2D(unsigned int index, unsigned int type, unsigned int stride, const void* pointer) { Bind(); VertexAttribute(index, 2, type, false, stride, pointer); };

};

