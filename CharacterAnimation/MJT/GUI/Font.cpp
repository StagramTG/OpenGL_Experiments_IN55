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
	camera.update();

	VertexArrayObject vao;
	vao.bind();

	VertexBufferObject vbo(GL_DYNAMIC_DRAW);
	vbo.bind();
	// Set VBO data
	GLfloat vertices[] = {
		0.f, 0.f,
		1.f, 0.f,
		0.f, 1.f,
		1.f, 1.f
	};
	vbo.setData(std::vector<GLfloat>(vertices, vertices + 8));
	vbo.unbind();

	VertexBufferObject uvs(GL_DYNAMIC_DRAW);
	uvs.bind();
	// Set uvs data
	GLfloat texCoord[] = {
		0.f, 0.f,
		1.f, 0.f,
		0.f, 1.f,
		1.f, 1.f
	};
	uvs.setData(std::vector<GLfloat>(texCoord, texCoord + 8));
	uvs.unbind();

	vao.unbind();

	ShaderProgram shader;
	shader.init("Assets/Shaders/Fonts/vertex.glsl", "Assets/Shaders/Fonts/fragment.glsl");
	shader.use();

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

		// Create glyph
		Glyph glyph;
		glyph.texPosition = glm::vec2(x, y + face->glyph->bitmap_top);
		glyph.size = glm::vec2(face->glyph->bitmap.width, face->glyph->bitmap.rows);
		glyph.bearing = glm::vec2(face->glyph->bitmap_left, face->glyph->bitmap_top);
		glyph.advance = face->glyph->advance.x;

		// Set the data to Texture for current glyph
		tmpGlyphTex.bind();
		tmpGlyphTex.setData(glyph.size.x, glyph.size.y, face->glyph->bitmap.buffer);

		// Create glyph's model matrix
		glm::mat4 glyphMat;
		glyphMat = glm::translate(glyphMat, glm::vec3(x, y, 0.f)) * glm::scale(glyphMat, glm::vec3(glyph.size.x, glyph.size.y, 0.f));

		// Bind uniforms for scalling and positioning in texture
		GLuint mvp = shader.getUniformLocation("mvp");
		shader.setUniformMat4(mvp, camera.getMatrix() * glyphMat);

		// draw call
		vao.bind();

		vao.enableAttribArray(0);
		vbo.bind();
		vao.attribPointer(0, 2, GL_FLOAT, GL_FALSE, 0);

		vao.enableAttribArray(1);
		uvs.bind();
		vao.attribPointer(1, 2, GL_FLOAT, GL_FALSE, 0);

		glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);

		uvs.unbind();
		vao.unbind();

		// Add the glyph to glyphs
		glyphs.insert(std::pair<char, Glyph>((char)c, glyph));

		// calc next x and y positions
		x += glyph.size.x + glyph.bearing.x;
		if (x > 512)
		{
			x = 0;
			y += fontSize;
		}
	}

	shader.done();
}

void mjt::gui::Font::loadToTexture()
{
}
