#include "Texture.h"

namespace mjt
{
	Texture::Texture(const char * file)
	{
		FREE_IMAGE_FORMAT imageFormat = FreeImage_GetFileType(file);
		FIBITMAP* image(0);

		image = FreeImage_Load(imageFormat, file);

		BYTE* data = FreeImage_GetBits(image);

		/*Generate OpenGL texture*/
		glGenTextures(1, &m_id);
		bind();
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

		// set the texture wrapping/filtering options (on the currently bound texture object)
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
		glGenerateMipmap(GL_TEXTURE_2D);
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

		/*Load image from file*/
		int width, height;
		/*Load data from file*/
		width = FreeImage_GetWidth(image);
		height = FreeImage_GetHeight(image);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);

		unbind();

		FreeImage_Unload(image);
	}

	Texture::Texture(GLuint nativeHandle)
	{
		m_id = nativeHandle;
	}

	Texture::Texture(GLuint width, GLuint height, GLint format)
	{
		glGenTextures(1, &m_id);
		bind();

		// Create a texture with no data
		glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, NULL);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		unbind();
	}

	Texture::~Texture()
	{
		glDeleteTextures(1, &m_id);
	}

	void Texture::setData(GLuint width, GLuint height, const void * data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
	}

	void Texture::setSubImage(GLint xOffset, GLint yOffset, GLint width, GLint height, GLenum type, const void* data)
	{
		glTexSubImage2D(GL_TEXTURE_2D, 0, xOffset, yOffset, width, height, type, GL_UNSIGNED_BYTE, data);
	}

	void Texture::bind()
	{
		glActiveTexture(GL_TEXTURE0 + m_id);
		glBindTexture(GL_TEXTURE_2D, m_id);
	}

	void Texture::unbind()
	{
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	GLuint Texture::getId()
	{
		return m_id;
	}
}