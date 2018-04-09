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
			FT_Library lib;

		public:
			Font();
			~Font();
		};
	}
}