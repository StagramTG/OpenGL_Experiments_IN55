#include "GuiManager.h"

#include <iostream>

mjt::gui::GuiManager::GuiManager(int width, int height)
{
	CameraSettings camSettings;
	camSettings.top = 0;
	camSettings.left = 0;
	camSettings.right = width;
	camSettings.bottom = height;

	camera = new OrthoCamera(camSettings);

	m_shader = new ShaderProgram();
	m_shader->init("Assets/Shaders/Fonts/vertex.glsl", "Assets/Shaders/Fonts/fragment.glsl");
}

mjt::gui::GuiManager::~GuiManager()
{
	delete camera;
	delete m_shader;
}

void mjt::gui::GuiManager::update()
{
	camera->update();

	for (GuiElement* element : m_elements)
	{
		element->update();
	}
}

void mjt::gui::GuiManager::render()
{
	m_shader->use();

	for (GuiElement* element : m_elements)
	{
		element->render(m_shader, camera);
	}
	
	m_shader->done();
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
