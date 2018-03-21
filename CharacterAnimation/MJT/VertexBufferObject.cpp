#include "VertexBufferObject.h"

namespace mjt
{
	VertexBufferObject::VertexBufferObject():
		BufferObject(GL_ARRAY_BUFFER)
	{
	}

	VertexBufferObject::~VertexBufferObject()
	{
	}

	void VertexBufferObject::setData(std::vector<GLfloat> data)
	{
		glBufferData(m_target, data.size() * sizeof(GLfloat), &data[0], GL_STATIC_DRAW);
	}
}
