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

		// set the texture wrapping/filtering options (on the currently bound texture object)
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);	
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

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

	Texture::Texture(GLuint width, GLuint height)
	{
	}

	Texture::~Texture()
	{
		glDeleteTextures(1, &m_id);
	}

	void Texture::bind()
	{
		glActiveTexture(GL_TEXTURE0);
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