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
