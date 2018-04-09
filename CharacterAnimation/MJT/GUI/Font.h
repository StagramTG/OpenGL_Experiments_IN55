#pragma once

#include "../FreeType/ft2build.h"
#include FT_FREETYPE_H

namespace mjt
{
	namespace gui
	{
		class Font
		{
		private:

		public:
			Font();
			Font(const char* fontFile);
			~Font();

			void loadFromFile(const char* fontFile);
			void loadToTexture();
		};
	}
}