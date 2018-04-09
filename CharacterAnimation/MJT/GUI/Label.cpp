#include "Label.h"

mjt::gui::Label::Label(): GuiElement()
{
}

mjt::gui::Label::~Label()
{
}

void mjt::gui::Label::setString(std::string text)
{
	m_text.setString(text);
}

void mjt::gui::Label::setPosition(glm::vec2 position)
{
	m_text.setPosition(position.x, position.y);
}

void mjt::gui::Label::update()
{
}

void mjt::gui::Label::render()
{

}
