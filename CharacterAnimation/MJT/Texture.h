#pragma once

#include <SFML\Graphics.hpp>

namespace mjt
{
	class Texture
	{
	private:
		sf::Texture* m_texture;

	public:
		Texture(const char* file);
		~Texture();

		void bind();
		void unbind();
	};
}