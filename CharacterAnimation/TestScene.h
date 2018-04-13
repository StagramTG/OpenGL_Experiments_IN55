#pragma once

#include "MJT/Scene.h"

#include "MJT/OglWindowAbs.h"
#include "MJT/ShaderProgram.h"
#include "MJT/PerspectiveCamera.h"
#include "MJT/Texture.h"
#include "MJT/AmbiantLight.h"

#include "TestSceneNode.h"
#include "FloorSceneNode.h"

#include "MJT/ColoredModel.h"

#include "MJT/GUI/GuiManager.h"
#include "MJT/GUI/Label.h"

class TestScene : public mjt::Scene 
{
private:
	mjt::ShaderProgram* m_shader;
	mjt::PerspectiveCamera* m_camera;

	mjt::AmbiantLight* m_ambiantLight;

	mjt::gui::GuiManager* m_gui;
	mjt::gui::Font* font;
	mjt::gui::Label* label;

public:
	TestScene() : mjt::Scene("Main")
	{
	}

	~TestScene()
	{
		delete m_shader;
		delete m_camera;

		delete label;
		delete font;
		delete m_gui;
	}

	void init()
	{
		addNode(new TestSceneNode());
		addNode(new FloorSceneNode());

		m_shader = new mjt::ShaderProgram();
		m_shader->init("Assets/Shaders/vertex.glsl", "Assets/Shaders/fragment.glsl");

		mjt::CameraSettings settings;
		settings.znear = 1.f;

		m_camera = new mjt::PerspectiveCamera(settings);
		m_camera->setPosition(glm::vec3(2.f, 2.f, 3.f));

		mjt::AmbiantLightData ambiantLightData;
		ambiantLightData.intensity = 0.2f;
		ambiantLightData.color = glm::vec3(1.f, 1.f, 1.f);

		m_ambiantLight = new mjt::AmbiantLight(ambiantLightData);

		m_gui = new mjt::gui::GuiManager(1280, 720);
		font = new mjt::gui::Font("Assets/Fonts/OpenSans.ttf", 18);
		label = new mjt::gui::Label(font, "Test de texte !");

		m_gui->addElement(label);
	}

	virtual void update()
	{
		m_camera->update();
		m_gui->update();

		mjt::Scene::update();
	}

	virtual void render(mjt::ShaderProgram* shader, mjt::Camera* camera)
	{
		m_shader->use();

		GLuint aIntensity = m_shader->getUniformLocation("ambiant.intensity");
		GLuint aColor = m_shader->getUniformLocation("ambiant.color");

		m_shader->setUniformFloat(aIntensity, m_ambiantLight->getIntensity());
		m_shader->setUniformVec3Float(aColor, m_ambiantLight->getColor());

		mjt::Scene::render(m_shader, m_camera);

		//m_shader->done();

		m_gui->render();
	}
};