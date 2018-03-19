#include "ColoredModel.h"

namespace mjt
{
	ColoredModel::ColoredModel(
		GLenum drawMode,
		std::vector<GLfloat> vertices, 
		std::vector<GLfloat> colors, 
		std::vector<GLuint> indices
	):
		Model(drawMode)
	{
		m_verticesCount = indices.size();

		m_vao = new VertexArrayObject();
		m_vao->bind();

		/*Build VBO*/
		m_vao->enableAttribArray(0);
		m_vbo = new VertexBufferObject();
		m_vbo->bind();
		m_vbo->setData(vertices);
		m_vao->attribPointer(0, 3, GL_FLOAT, GL_FALSE, 0);
		m_vbo->unbind();

		/*Build CBO*/
		m_vao->enableAttribArray(1);
		m_cbo = new VertexBufferObject();
		m_cbo->bind();
		m_cbo->setData(colors);
		m_vao->attribPointer(1, 3, GL_FLOAT, GL_FALSE, 0);
		m_cbo->unbind();


		/*Build IBO*/
		m_ibo = new IndicesBufferObject();
		m_ibo->bind();
		m_ibo->setData(indices);

		m_vao->unbind();
	}

	ColoredModel::~ColoredModel()
	{
		delete m_vbo;
		delete m_cbo;
		delete m_ibo;
		delete m_vao;
	}

	void ColoredModel::render()
	{
		m_vao->bind();
		glDrawElements(m_drawMode, m_verticesCount, GL_UNSIGNED_INT, 0);
	}
}
