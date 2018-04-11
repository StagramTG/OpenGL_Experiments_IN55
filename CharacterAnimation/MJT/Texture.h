#pragma once

#include <GL/glew.h>
#include <FreeImage.h>

namespace mjt
{
	class Texture
	{
	private:
		GLuint m_id;

	public:
		// Load texture from file
		Texture(const char* file);
		// Only reference a texture created outside this class
		Texture(GLuint nativeHandle);
		// Create an empty texture
		Texture(GLuint width, GLuint height);

		~Texture();

		void setData(GLuint width, GLuint height, const void* data);
		void setSubImage(GLint xOffset, GLint yOffset, GLint width, GLint height, GLenum type, const void* data);

		void bind();
		void unbind();
		GLuint getId();
	};
}