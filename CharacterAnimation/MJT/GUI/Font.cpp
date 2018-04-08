#include "Font.h"
#include <iostream>

namespace mjt
{
	namespace gui
	{
		Font::Font(const char* fontFile, GLuint fontSize)
		{
			// Load font from file
			bool success = m_font.loadFromFile(fontFile);

			if (!success)
			{
				std::cerr << "[FONT LOADING] Error while loading font file " << fontFile << std::endl;
				exit(EXIT_FAILURE);
			}

			// Get texture id
			m_texture = new Texture(m_font.getTexture(fontSize).getNativeHandle());
		}

		Font::~Font()
		{
			delete m_texture;
		}

		Texture * Font::getTexture()
		{
			return m_texture;
		}
	}
}
