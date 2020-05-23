#include "VertexArray.h"


VertexArray::VertexArray() {
	glCreateVertexArrays(1, &m_VAO_ID);
	glBindVertexArray(m_VAO_ID);
	VertexArray::BindNone();
}

VertexArray::~VertexArray() {
	glDeleteVertexArrays(1, &m_VAO_ID);
}

void VertexArray::Bind() {
	glBindVertexArray(m_VAO_ID);
}

void VertexArray::BindNone() {
	glBindVertexArray(0);
}
void VertexArray::EnableAttribute(unsigned int index) {
	Bind();
	glEnableVertexAttribArray(index);
}

void VertexArray::DisableAttribute(unsigned int index) {
	Bind();
	glDisableVertexAttribArray(index);
}

void VertexArray::VertexAttribute(unsigned int index, int size, unsigned int type, bool normalized, unsigned int stride, const void* pointer)
{
	Bind();
	glVertexAttribPointer(index, size, type, normalized, stride, pointer);
}


