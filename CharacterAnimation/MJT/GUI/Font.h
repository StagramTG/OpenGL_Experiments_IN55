#pragma once

#include <ft2build.h>
#include FT_FREETYPE_H
#include <map>
#include <vector>
#include <glm/gtc/matrix_transform.hpp>

#include "../Texture.h"
#include "Glyph.h"

namespace mjt
{
	namespace gui
	{
		class Font
		{
		private:
			Texture * m_texture;
			std::map<char, Glyph> m_glyphs;

		public:
			Font();
			Font(const char* fontFile, int fontSize);
			~Font();

			void loadFromFile(const char* fontFile, int fontSize);
			void loadToTexture();

			Texture* getTexture();
			Glyph getGlyph(const char c);
		};
	}
}