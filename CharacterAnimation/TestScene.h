#pragma once

#include "MJT/Scene.h"

#include "MJT/OglWindowAbs.h"
#include "MJT/ShaderProgram.h"
#include "MJT/PerspectiveCamera.h"
#include "MJT/Texture.h"

#include "TestSceneNode.h"

class TestScene : public mjt::Scene 
{
private:
	TestSceneNode * testNode;

	mjt::ShaderProgram* shader;
	mjt::PerspectiveCamera* camera;

public:
	TestScene() : mjt::Scene("Main")
	{

	}

	~TestScene()
	{
		delete shader;
		delete camera;
	}

	void init()
	{
		TestSceneNode* node = new TestSceneNode();
		addNode(node);

		shader = new mjt::ShaderProgram();
		shader->init("Assets/Shaders/vertex.glsl", "Assets/Shaders/fragment.glsl");

		camera = new mjt::PerspectiveCamera(mjt::CameraSettings());
		camera->setPosition(glm::vec3(3.f, 3.f, 4.f));
	}

	virtual void update()
	{
		camera->update();

		mjt::Scene::update();
	}

	virtual void render()
	{
		shader->use();
		GLuint loc = shader->getUniformLocation("mvp");
		shader->setUniformMat4(loc, camera->getMatrix() * glm::scale(glm::mat4(1.0f), glm::vec3(1.0f)));

		mjt::Scene::render();

		shader->done();
	}
};