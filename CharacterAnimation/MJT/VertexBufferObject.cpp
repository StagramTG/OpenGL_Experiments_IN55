#include "VertexBufferObject.h"

namespace mjt
{
	VertexBufferObject::VertexBufferObject(GLenum drawMode):
		BufferObject(GL_ARRAY_BUFFER)
	{
		m_drawMode = drawMode;
	}

	VertexBufferObject::~VertexBufferObject()
	{
	}

	void VertexBufferObject::setData(std::vector<GLfloat> data)
	{
		glBufferData(m_target, data.size() * sizeof(GLfloat), &data[0], m_drawMode);
	}

	void VertexBufferObject::setSubData(std::vector<GLfloat> data)
	{
		glBufferSubData(m_target, 0, data.size() * sizeof(GLfloat), &data[0]);
	}
}
