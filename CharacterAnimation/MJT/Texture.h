#pragma once

#include <SFML/Graphics.hpp>
#include <GL/glew.h>

namespace mjt
{
	class Texture
	{
	private:
		sf::Image* m_texture;

	public:
		Texture(const char* file);
		~Texture();

		void bind();
		void unbind();
		GLuint getId();
	};
}