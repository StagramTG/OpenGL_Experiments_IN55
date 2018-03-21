#pragma once

#include <GL\glew.h>

namespace mjt
{
	class BufferObject
	{
	protected:
		GLuint m_id;
		GLenum m_target;

	public:
		BufferObject(GLenum target);
		~BufferObject();

		void bind();
		void unbind();
	};
}
