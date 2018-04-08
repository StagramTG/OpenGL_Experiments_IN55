#pragma once

#include <GL/glew.h>
#include <SFML/Graphics.hpp>

#include "../Texture.h"

namespace mjt
{
	namespace gui
	{
		/*
			Class Font.

			Load a font and put it in a Texture object to use
		*/
		class Font
		{
		private:
			sf::Font m_font;
			Texture* m_texture;

		public:
			Font(const char* fontFile, GLuint fontSize);
			~Font();

			Texture* getTexture();
		};
	}
}