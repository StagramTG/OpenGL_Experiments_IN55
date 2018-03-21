#include "VertexArrayObject.h"

namespace mjt
{
	VertexArrayObject::VertexArrayObject()
	{
		glGenVertexArrays(1, &m_id);
	}

	VertexArrayObject::~VertexArrayObject()
	{
		glDeleteVertexArrays(1, &m_id);
	}

	void VertexArrayObject::bind()
	{
		glBindVertexArray(m_id);
	}

	void VertexArrayObject::unbind()
	{
		glBindVertexArray(0);
	}

	void VertexArrayObject::enableAttribArray(GLuint id)
	{
		glEnableVertexAttribArray(id);
	}

	void VertexArrayObject::disableAttribArray(GLuint id)
	{
		glDisableVertexAttribArray(id);
	}

	void VertexArrayObject::attribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride)
	{
		glVertexAttribPointer(index, size, type, normalized, stride, (void*)0);
	}
}
