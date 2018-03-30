#pragma once

#include "Model.h"
#include "VertexArrayObject.h"
#include "VertexBufferObject.h"
#include "IndicesBufferObject.h"
#include "Texture.h"

#include <vector>

namespace mjt
{
	class TexturedModel: public Model
	{
	private:
		VertexArrayObject* m_vao;
		VertexBufferObject* m_vbo;
		VertexBufferObject* m_tbo;
		IndicesBufferObject* m_ibo;
		Texture* m_texture;

	public:
		TexturedModel(
			GLenum drawMode, 
			std::vector<GLfloat> vertices, 
			std::vector<GLfloat> uvs, 
			std::vector<GLuint> indices, 
			const char* texture
		);
		~TexturedModel();

		void render(ShaderProgram* shader, Camera* camera) override;
	};
}
