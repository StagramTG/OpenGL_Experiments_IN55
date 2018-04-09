#include "Font.h"
#include <iostream>

mjt::gui::Font::Font()
{
}

mjt::gui::Font::Font(const char* fontFile)
{
	loadFromFile(fontFile);
}

mjt::gui::Font::~Font()
{
}

void mjt::gui::Font::loadFromFile(const char * fontFile)
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
}

void mjt::gui::Font::loadToTexture()
{
}
