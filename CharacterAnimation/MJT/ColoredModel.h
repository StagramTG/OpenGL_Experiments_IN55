#pragma once

#include "Model.h"

#include "VertexArrayObject.h"
#include "VertexBufferObject.h"
#include "IndicesBufferObject.h"

namespace mjt
{
	class ColoredModel: public Model
	{
	private:
		VertexArrayObject* m_vao;
		VertexBufferObject* m_vbo;
		VertexBufferObject* m_cbo;
		IndicesBufferObject* m_ibo;

	public:
		ColoredModel(
			GLenum drawMode, 
			std::vector<GLfloat> vertices, 
			std::vector<GLfloat> colors, 
			std::vector<GLuint> indices
		);
		~ColoredModel();

		void render(ShaderProgram* shader, Camera* camera) override;
	};
}
