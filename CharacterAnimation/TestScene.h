#pragma once

#include "MJT/Scene.h"

#include "MJT/OglWindowAbs.h"
#include "MJT/ShaderProgram.h"
#include "MJT/PerspectiveCamera.h"
#include "MJT/Texture.h"

#include "TestSceneNode.h"
#include "FloorSceneNode.h"

class TestScene : public mjt::Scene 
{
private:
	mjt::ShaderProgram* m_shader;
	mjt::PerspectiveCamera* m_camera;

public:
	TestScene() : mjt::Scene("Main")
	{

	}

	~TestScene()
	{
		delete m_shader;
		delete m_camera;
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
	}

	virtual void update()
	{
		m_camera->update();

		mjt::Scene::update();
	}

	virtual void render(mjt::ShaderProgram* shader, mjt::Camera* camera)
	{
		m_shader->use();

		mjt::Scene::render(m_shader, m_camera);

		m_shader->done();
	}
};