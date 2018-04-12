#include "GuiManager.h"

mjt::gui::GuiManager::GuiManager(int width, int height)
{
	CameraSettings camSettings;
	camSettings.top = 0;
	camSettings.left = 0;
	camSettings.right = width;
	camSettings.bottom = height;

	camera = new OrthoCamera(camSettings);
	camera->update();
}

mjt::gui::GuiManager::~GuiManager()
{
}

void mjt::gui::GuiManager::update()
{
	for (GuiElement* element : m_elements)
	{
		element->update();
	}
}

void mjt::gui::GuiManager::render(ShaderProgram* shader)
{
	for (GuiElement* element : m_elements)
	{
		element->render(shader, camera);
	}
}

bool mjt::gui::GuiManager::addElement(GuiElement * element)
{
	if (element != nullptr)
	{
		m_elements.push_back(element);
		return true;
	}

	return false;
}

bool mjt::gui::GuiManager::removeElement(GuiElement * element)
{
	for (size_t i = 0; i < m_elements.size(); ++i)
	{
		if (m_elements[i] == element)
		{
			m_elements.erase(m_elements.begin() + i);
			return true;
		}
	}

	return false;
}
