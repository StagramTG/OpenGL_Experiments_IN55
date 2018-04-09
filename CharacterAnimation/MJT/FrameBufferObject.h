#pragma once

#include <GL/glew.h>
#include "Texture.h"

namespace mjt
{
	class FrameBufferObject
	{
	private:
		GLuint m_id;
		Texture* m_texture;

	public:
		FrameBufferObject();
		~FrameBufferObject();

		void bind();
		void unbind();

		void setTexture(Texture* texture);
		Texture* getTexture();
	};
}