#pragma once

#include <GL\glew.h>

namespace mjt
{
	class Model
	{
	protected:
		int m_verticesCount;
		GLenum m_drawMode;

	public:
		Model(GLenum drawMode) { m_drawMode = drawMode; }
		~Model() {}

		virtual void render() = 0;
	};
}
