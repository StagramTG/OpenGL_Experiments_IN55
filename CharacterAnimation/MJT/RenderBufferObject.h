#pragma once

#include <GL/glew.h>

namespace mjt
{
	class RenderBufferObject
	{
	private:
		GLuint m_id;

	public:
		RenderBufferObject(int width, int height, GLenum internalFormat = GL_DEPTH24_STENCIL8);
		~RenderBufferObject();

		void bind();
		void unbind();

		GLuint getId();
	};
}