#include "IndicesBufferObject.h"

namespace mjt
{
	IndicesBufferObject::IndicesBufferObject(): 
		BufferObject(GL_ELEMENT_ARRAY_BUFFER)
	{
	}

	IndicesBufferObject::~IndicesBufferObject()
	{
	}

	void IndicesBufferObject::setData(std::vector<GLuint> data)
	{
		glBufferData(m_target, data.size() * sizeof(GLuint), &data[0], GL_STATIC_DRAW);
	}
}
