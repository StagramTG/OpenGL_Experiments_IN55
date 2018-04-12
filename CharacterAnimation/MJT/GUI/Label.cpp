#include "Label.h"
#include "../Utils/MeshUtils.h"
#include <iostream>

mjt::gui::Label::Label(): GuiElement()
{
}

mjt::gui::Label::Label(Font* font, std::string text)
{
	m_text = text;
	m_font = font;
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
}

void mjt::gui::Label::update()
{
}

void mjt::gui::Label::render(ShaderProgram* shader, Camera* camera)
{

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
	std::vector<GLfloat> indices;

	mjt::utils::MeshData meshData;
	Glyph currentGlyph;
	GLfloat x = 0;

	for (const char* c = m_text.c_str(); *c; ++c)
	{
		currentGlyph = m_font->getGlyph(*c);
		meshData = mjt::utils::MeshUtils::createSquare(
			x, currentGlyph.bearing.y, currentGlyph.size.x, currentGlyph.size.y,
			currentGlyph.texPosition.x, currentGlyph.texPosition.y, currentGlyph.size.x, currentGlyph.size.y
		);

		vertices.insert(vertices.end(), meshData.vertices.begin(), meshData.vertices.end());
		uvs.insert(uvs.end(), meshData.uvs.begin(), meshData.uvs.end());
		indices.insert(indices.end(), meshData.indices.begin(), meshData.indices.end());
	}

	
}