#pragma once

#include <vector>
#include "BufferObject.h"

namespace mjt
{
	class VertexBufferObject: public BufferObject
	{
	private:
		GLenum m_drawMode;

	public:
		VertexBufferObject(GLenum drawMode = GL_STATIC_DRAW);
		~VertexBufferObject();

		void setData(std::vector<GLfloat> data);
		void setSubData(std::vector<GLfloat> data);
	};
}
