#pragma once

#include <ft2build.h>
#include FT_FREETYPE_H
#include <map>
#include <vector>
#include <glm/gtc/matrix_transform.hpp>

#include "../FrameBufferObject.h"
#include "../OrthoCamera.h"
#include "Glyph.h"

#include "../VertexArrayObject.h"
#include "../VertexBufferObject.h"

#include "../ShaderProgram.h"

namespace mjt
{
	namespace gui
	{
		class Font
		{
		private:
			std::map<char, Glyph> glyphs;
			FrameBufferObject * m_fbo;

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
	- Create a VAO with vbo and uvs buffers
	- Create shaders to "print" glyphs on texture
	- Create drawing code
*/