#include "Buffer.h"


Buffer::Buffer(unsigned int target, unsigned int count, const void* data, BufferDataType dataType) {
	m_bufferTarget = target;
	m_bufferUsage = GL_STATIC_DRAW;
	m_dataType = dataType;

	glGenBuffers(1, &m_BufferID);
	glBindBuffer(m_bufferTarget, m_BufferID);
	switch (m_dataType) {
	case FLOAT:
		glBufferData(m_bufferTarget, sizeof(GLfloat) * count, data, m_bufferUsage);
		break;
	case UINT:
		glBufferData(m_bufferTarget, sizeof(GLuint) * count, data, m_bufferUsage);
		break;
	case SHORT:
		glBufferData(m_bufferTarget, sizeof(GLshort) * count, data, m_bufferUsage);
		break;
	}

}

Buffer::Buffer(unsigned int target, unsigned int count, const void* data, unsigned int usage, BufferDataType dataType)
{
	m_bufferTarget = target;
	m_bufferUsage = usage;
	m_dataType = dataType;

	glGenBuffers(1, &m_BufferID);
	glBindBuffer(m_bufferTarget, m_BufferID);
	switch (m_dataType) {
	case FLOAT:
		glBufferData(m_bufferTarget, sizeof(GLfloat) * count, data, m_bufferUsage);
		break;
	case UINT:
		glBufferData(m_bufferTarget, sizeof(GLuint) * count, data, m_bufferUsage);
		break;
	case SHORT:
		glBufferData(m_bufferTarget, sizeof(GLshort) * count, data, m_bufferUsage);
		break;
	}
}

Buffer::~Buffer()
{
	glDeleteBuffers(1, &m_BufferID);
}

void Buffer::Bind()
{
	glBindBuffer(m_bufferTarget, m_BufferID);
}

void Buffer::Unbind() {
	Buffer::BindNone(m_bufferTarget);
}

void Buffer::BindNone(unsigned int target)
{
	glBindBuffer(target, 0);
}
