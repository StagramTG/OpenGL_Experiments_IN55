#pragma once

#include <ft2build.h>
#include FT_FREETYPE_H
#include <map>
#include <vector>
#include <glm/gtc/matrix_transform.hpp>

#include "Glyph.h"

namespace mjt
{
	namespace gui
	{
		class Font
		{
		private:
			std::map<char, Glyph> glyphs;

		public:
			Font();
			Font(const char* fontFile, int fontSize);
			~Font();

			void loadFromFile(const char* fontFile, int fontSize);
			void loadToTexture();
		};
	}
}

/*
	- Use glTexSubImage2D to draw each glyph on texture
*/