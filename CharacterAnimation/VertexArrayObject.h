#pragma once

#include <GL\glew.h>

namespace mjt
{
	class VertexArrayObject
	{
	private:
		GLuint m_id;

	public:
		VertexArrayObject();
		~VertexArrayObject();

		void bind();
		void unbind();

		void enableAttribArray(GLuint id);
		void disableAttribArray(GLuint id);
		void attribPointer(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride);
	};
}
