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
	if (!m_fbo->isComplete())
	{
		std::cerr << "[FONT] Error while creating FBO for font" << std::endl;
		return;
	}

	// Create each glyph and render to FrameBufferObject, so on texture.
}

void mjt::gui::Font::loadToTexture()
{
}
