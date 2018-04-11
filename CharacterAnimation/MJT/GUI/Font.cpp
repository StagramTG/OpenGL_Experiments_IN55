#include "Font.h"
#include <iostream>

mjt::gui::Font::Font()
{
}

mjt::gui::Font::Font(const char* fontFile, int fontSize)
{
	loadFromFile(fontFile, fontSize);
}

mjt::gui::Font::~Font()
{
	delete m_fbo;
}

void mjt::gui::Font::loadFromFile(const char * fontFile, int fontSize)
{
	FT_Library fontLib;
	FT_Error initSuccess = FT_Init_FreeType(&fontLib);

	if(initSuccess)
	{
		std::cerr << "[FONT] Error while loading " << fontFile << std::endl;
		exit(EXIT_FAILURE);
	}

	FT_Face face;
	FT_Error faceSuccess = FT_New_Face(fontLib, fontFile, 0, &face);

	if(faceSuccess)
	{
		std::cerr << "[FONT] Error while loading " << fontFile << std::endl;
		exit(EXIT_FAILURE);
	}

	FT_Set_Pixel_Sizes(face, 0, 48);

	// Create each glyph and render to FrameBufferObject, so on texture.
	Texture tmpGlyphTex(25, 25);
	GLuint x = 0, y = 0;
	for (GLubyte c = 0; c < 128; ++c)
	{
		if (FT_Load_Char(face, c, FT_LOAD_RENDER))
		{
			std::cerr << "[FONT] Can't load character " << c << std::endl;
			continue;
		}
	}
}

void mjt::gui::Font::loadToTexture()
{
}
