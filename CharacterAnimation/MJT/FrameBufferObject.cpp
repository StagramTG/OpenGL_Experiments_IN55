#include "FrameBufferObject.h"

mjt::FrameBufferObject::FrameBufferObject()
{
	glGenFramebuffers(1, &m_id);
}

mjt::FrameBufferObject::~FrameBufferObject()
{
	glDeleteFramebuffers(1, &m_id);
}

void mjt::FrameBufferObject::bind()
{
	glBindFramebuffer(GL_FRAMEBUFFER, m_id);
}

void mjt::FrameBufferObject::unbind()
{
	glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

void mjt::FrameBufferObject::setTexture(mjt::Texture * texture)
{
	m_texture = texture;

	bind();
	glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, m_texture->getId(), 0);
	unbind();
}

mjt::Texture * mjt::FrameBufferObject::getTexture()
{
	return m_texture;
}

void mjt::FrameBufferObject::setRenderBuffer(mjt::RenderBufferObject * renderBuffer)
{
	m_renderBuffer = renderBuffer;

	bind();
	glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, m_renderBuffer->getId());
	unbind();
}

mjt::RenderBufferObject * mjt::FrameBufferObject::getRenderBuffer()
{
	return m_renderBuffer;
}

bool mjt::FrameBufferObject::isComplete()
{
	bind();
	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
	{
		unbind();
		return false;
	}

	unbind();
	return true;
}
