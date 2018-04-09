#pragma once

#include <GL/glew.h>

namespace mjt
{
	class FrameBufferObject
	{
	private:
		GLuint m_id;

	public:
		FrameBufferObject();
		~FrameBufferObject();

		void bind();
		void unbind();
	};
}