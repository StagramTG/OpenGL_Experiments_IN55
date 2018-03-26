#include "TexturedModel.h"

namespace mjt
{
	TexturedModel::TexturedModel(
		GLenum drawMode, 
		std::vector<GLfloat> vertices, 
		std::vector<GLfloat> uvs, 
		std::vector<GLuint> indices, 
		const char* texture
	): 
		Model(drawMode)
	{
		m_verticesCount = indices.size();

		/*Load texture*/
		m_texture = new Texture(texture);

		m_vao = new VertexArrayObject();
		m_vao->bind();

		/*Build VBO*/
		m_vao->enableAttribArray(0);
		m_vbo = new VertexBufferObject();
		m_vbo->bind();
		m_vbo->setData(vertices);
		m_vao->attribPointer(0, 3, GL_FLOAT, GL_FALSE, 0);
		m_vbo->unbind();

		/*Build TBO*/
		m_vao->enableAttribArray(1);
		m_tbo = new VertexBufferObject();
		m_tbo->bind();
		m_tbo->setData(uvs);
		m_vao->attribPointer(1, 2, GL_FLOAT, GL_FALSE, 0);
		m_tbo->unbind();


		/*Build IBO*/
		m_ibo = new IndicesBufferObject();
		m_ibo->bind();
		m_ibo->setData(indices);

		m_vao->unbind();
	}


	TexturedModel::~TexturedModel()
	{
		delete m_vbo;
		delete m_tbo;
		delete m_ibo;

		delete m_vao;
		delete m_texture;
	}

	void TexturedModel::render()
	{
		m_texture->bind();
		m_vao->bind();

		glDrawElements(m_drawMode, m_verticesCount, GL_UNSIGNED_INT, 0);

		m_vao->unbind();
		m_texture->unbind();
	}
}
