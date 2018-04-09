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
