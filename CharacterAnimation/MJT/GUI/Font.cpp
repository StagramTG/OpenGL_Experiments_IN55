#include "Font.h"
#include <iostream>
#include <algorithm>

mjt::gui::Font::Font()
{
}

mjt::gui::Font::Font(const char* fontFile, int fontSize)
{
	loadFromFile(fontFile, fontSize);
}

mjt::gui::Font::~Font()
{
	delete m_texture;
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

	FT_Set_Pixel_Sizes(face, 0, fontSize);

	m_texture = new mjt::Texture(512, 512, GL_RED);
	m_texture->bind();

	GLint x = 0, y = 0, nextY = 0;
	for (GLubyte c = 32; c < 128; ++c)
	{
		if (FT_Load_Char(face, c, FT_LOAD_RENDER))
		{
			std::cerr << "[FONT] Can't load character: " << c << std::endl;
			continue;
		}

		// Check if height is gretter than before
		nextY = std::max(nextY, (GLint)face->glyph->bitmap.rows);

		// Check if Create a new line for this character
		if ((x + face->glyph->bitmap.width) > 512)
		{
			x = 0;
			y += nextY + 2;
			nextY = 0;
		}

		Glyph glyph;
		glyph.size = glm::vec2(face->glyph->bitmap.width, face->glyph->bitmap.rows);
		glyph.texPosition = glm::vec2(x, y);
		glyph.advance = face->glyph->advance.x >> 6;
		glyph.bearing = glm::vec2(face->glyph->bitmap_left, face->glyph->bitmap_top);

		// Push glyph in list
		m_glyphs.insert(std::pair<char, Glyph>((char)c, glyph));

		// Add to texture
		m_texture->setSubImage(x, y, face->glyph->bitmap.width, face->glyph->bitmap.rows, GL_RED, face->glyph->bitmap.buffer);

		// increment x pos
		x += face->glyph->bitmap.width + 2;
	}

	m_texture->unbind();
}

void mjt::gui::Font::loadToTexture()
{
}

mjt::Texture * mjt::gui::Font::getTexture()
{
	return m_texture;
}

mjt::gui::Glyph mjt::gui::Font::getGlyph(const char c)
{
	return m_glyphs[c];
}
