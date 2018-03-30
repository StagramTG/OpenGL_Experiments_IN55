#pragma once

#include <GL/glew.h>

namespace mjt
{
	class Texture
	{
	private:
		GLuint m_id;

	public:
		Texture(const char* file);
		~Texture();

		void bind();
		void unbind();
		GLuint getId();
	};
}