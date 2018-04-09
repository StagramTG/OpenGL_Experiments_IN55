#pragma once

#include <GL/glew.h>
#include "Texture.h"
#include "RenderBufferObject.h"

namespace mjt
{
	class FrameBufferObject
	{
	private:
		GLuint m_id;
		Texture* m_texture;
		RenderBufferObject* m_renderBuffer;

	public:
		FrameBufferObject();
		~FrameBufferObject();

		void bind();
		void unbind();

		void setTexture(Texture* texture);
		Texture* getTexture();

		void setRenderBuffer(RenderBufferObject* renderBuffer);
		RenderBufferObject* getRenderBuffer();

		bool isComplete();
	};
}