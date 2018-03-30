#include "Texture.h"

namespace mjt
{
	Texture::Texture(const char * file)
	{
		m_texture = new sf::Image();
		m_texture->loadFromFile(file);
	}

	Texture::~Texture()
	{
		delete m_texture;
	}

	void Texture::bind()
	{

	}

	void Texture::unbind()
	{

	}

	GLuint Texture::getId()
	{

	}
}