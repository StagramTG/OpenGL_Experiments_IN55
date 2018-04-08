#pragma once

#include <GL/glew.h>
#include <SFML/Graphics.hpp>

namespace mjt
{
	namespace gui
	{
		class Font
		{
		private:
			sf::Font m_font;
			GLuint m_textureId;

		public:
			Font(const char* fontFile, GLuint fontSize);
			~Font();
		};
	}
}