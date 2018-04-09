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

	// Create and setup FrameBuffer to render texture
	m_fbo = new FrameBufferObject();

	Texture* texture = new Texture(512, 512);
	m_fbo->bind();
	m_fbo->setTexture(texture);

	RenderBufferObject* rbo = new RenderBufferObject(512, 512);
	m_fbo->setRenderBuffer(rbo);

	// Check if Framebuffer is complete
	bool isComplete = m_fbo->isComplete();
	if (!isComplete)
	{
		std::cerr << "[FONT] Error while creating FBO for font" << std::endl;
		return;
	}

	// Create Camera to render glyphs
	CameraSettings cSettings;
	cSettings.left = 0; cSettings.right = 512;
	cSettings.top = 0; cSettings.bottom = 512;

	OrthoCamera camera(cSettings);

	// Create each glyph and render to FrameBufferObject, so on texture.
	GLuint x = 0, y = 0;
	for (GLubyte c = 0; c < 128; ++c)
	{
		if (FT_Load_Char(face, c, FT_LOAD_RENDER))
		{
			std::cerr << "[FONT] Can't load character " << c << std::endl;
			continue;
		}

		// Create glyph
		Glyph glyph;
		glyph.texPosition = glm::vec2(x, y + face->glyph->bitmap_top);
		glyph.size = glm::vec2(face->glyph->bitmap.width, face->glyph->bitmap.rows);
		glyph.bearing = glm::vec2(face->glyph->bitmap_left, face->glyph->bitmap_top);
		glyph.advance = face->glyph->advance.x;

		// calc next x and y positions
		x += glyph.size.x + glyph.bearing.x;
		if (x > 512)
		{
			x = 0;
			y += fontSize;
		}

		// Draw in FrameBufferObject


		// Add the glyph to glyphs
		glyphs.insert(std::pair<char, Glyph>((char)c, glyph));
	}

}

void mjt::gui::Font::loadToTexture()
{
}
