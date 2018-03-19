#include "Texture.h"

namespace mjt
{
	Texture::Texture(const char * file)
	{
		m_texture = new sf::Texture();
		m_texture->loadFromFile(file);
	}

	Texture::~Texture()
	{
		delete m_texture;
	}

	void Texture::bind()
	{
		sf::Texture::bind(m_texture);
	}

	void Texture::unbind()
	{
		sf::Texture::bind(NULL);
	}
}