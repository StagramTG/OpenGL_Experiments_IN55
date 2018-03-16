#include "BufferObject.h"

namespace mjt
{
	BufferObject::BufferObject(GLenum target)
	{
		m_target = target;
		glGenBuffers(1, &m_id);
	}

	BufferObject::~BufferObject()
	{
		glDeleteBuffers(1, &m_id);
	}

	void BufferObject::bind()
	{
		glBindBuffer(m_target, m_id);
	}

	void BufferObject::unbind()
	{
		glBindBuffer(m_target, 0);
	}
}
