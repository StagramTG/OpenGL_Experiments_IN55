#include "Label.h"
#include "../Utils/MeshUtils.h"
#include <iostream>

mjt::gui::Label::Label(): GuiElement()
{
}

mjt::gui::Label::Label(Font* font, std::string text) : GuiElement()
{
	m_text = text;
	m_font = font;

	buildMesh();
}

mjt::gui::Label::~Label()
{
}

void mjt::gui::Label::setFont(Font * font)
{
	m_font = font;
}

void mjt::gui::Label::setText(std::string text)
{
	m_text = text;
	buildMesh();
}

void mjt::gui::Label::update()
{
	GuiElement::update();
}

void mjt::gui::Label::render(ShaderProgram* shader, Camera* camera)
{
	GuiElement::render(shader, camera);

	GLuint mvp = shader->getUniformLocation("mvp");
	shader->setUniformMat4(mvp, camera->getMatrix() * m_transform->getFromWorld());
	
	m_font->getTexture()->bind();
	GLuint texture = shader->getUniformLocation("texture");
	shader->setUniformInt(texture, m_font->getTexture()->getId());

	m_vao->bind();
	glDrawElements(GL_TRIANGLES, m_verticesCount, GL_UNSIGNED_INT, 0);
	m_vao->unbind();

	m_font->getTexture()->unbind();
}

void mjt::gui::Label::buildMesh()
{
	if (m_font == nullptr)
	{
		std::cerr << "[LABEL] No font set for label: " << m_text << std::endl;
		return;
	}

	std::vector<GLfloat> vertices;
	std::vector<GLfloat> uvs;
	std::vector<GLuint> indices;

	mjt::utils::MeshData meshData;
	Glyph currentGlyph;
	GLfloat x = 0;

	for (const char* c = m_text.c_str(); *c; ++c)
	{
		currentGlyph = m_font->getGlyph(*c);
		meshData = mjt::utils::MeshUtils::createSquare(
			x, currentGlyph.bearing.y, currentGlyph.size.x, currentGlyph.size.y,
			currentGlyph.texPosition.x, currentGlyph.texPosition.y, currentGlyph.size.x, currentGlyph.size.y,
			indices.size()
		);

		vertices.insert(vertices.end(), meshData.vertices.begin(), meshData.vertices.end());
		uvs.insert(uvs.end(), meshData.uvs.begin(), meshData.uvs.end());
		indices.insert(indices.end(), meshData.indices.begin(), meshData.indices.end());

		x += currentGlyph.advance + 2;
	}

	m_vao = new VertexArrayObject();
	m_vao->bind();

	m_vao->enableAttribArray(0);
	m_vbo = new VertexBufferObject();
	m_vbo->bind();
	m_vbo->setData(vertices);
	m_vao->attribPointer(0, 3, GL_FLOAT, GL_FALSE, 0);

	m_vao->enableAttribArray(1);
	m_uvs = new VertexBufferObject();
	m_uvs->bind();
	m_uvs->setData(uvs);
	m_vao->attribPointer(1, 2, GL_FLOAT, GL_FALSE, 0);
	m_uvs->unbind();

	m_indices = new IndicesBufferObject();
	m_indices->bind();
	m_indices->setData(indices);

	m_vao->unbind();

	m_verticesCount = indices.size();
	std::cout << m_verticesCount << std::endl;
}