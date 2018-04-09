#include "RenderBufferObject.h"

mjt::RenderBufferObject::RenderBufferObject(int width, int height, GLenum internalFormat)
{
	glGenRenderbuffers(1, &m_id);
	bind();
	glRenderbufferStorage(GL_RENDERBUFFER, internalFormat, width, height);
	unbind();
}

mjt::RenderBufferObject::~RenderBufferObject()
{
	glDeleteRenderbuffers(1, &m_id);
}

void mjt::RenderBufferObject::bind()
{
	glBindRenderbuffer(GL_RENDERBUFFER, m_id);
}

void mjt::RenderBufferObject::unbind()
{
	glBindRenderbuffer(GL_RENDERBUFFER, 0);
}

GLuint mjt::RenderBufferObject::getId()
{
	return m_id;
}
