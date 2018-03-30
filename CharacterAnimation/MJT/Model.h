#pragma once

#include <GL\glew.h>

#include "ShaderProgram.h"
#include "Camera.h"

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

		virtual void render(ShaderProgram* shader, Camera* camera) = 0;

		/*Constantes*/
		const static GLuint GLSL_LOC_POS = 0;
		const static GLuint GLSL_LOC_UVS = 1;
		const static GLuint GLSL_LOC_COL = 2;
	};
}
