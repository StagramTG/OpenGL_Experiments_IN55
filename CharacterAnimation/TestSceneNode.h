#pragma once

#include <iostream>

#include "MJT/SceneNode.h"
#include "MJT/ColoredModel.h"

class TestSceneNode : public mjt::SceneNode
{
private:
	mjt::ColoredModel* model;

public:
	TestSceneNode()
	{
		GLfloat vertices[] = {
			0.f, 1.f, 0.f,
			1.f, -1.f, 0.f,
			-1.f, -1.f, 0.f,
		};

		GLfloat colors[] = {
			1.f, 0.f, 0.f,
			0.f, 1.f, 0.f,
			0.f, 0.f, 1.f
		};

		GLuint index[] = {
			0, 1, 2
		};

		std::vector<GLfloat> data(vertices, vertices + 9);
		std::vector<GLfloat> col(colors, colors + 9);
		std::vector<GLuint> ind(index, index + 3);

		model = new mjt::ColoredModel(GL_TRIANGLES, data, col, ind);
		m_transform->move(glm::vec3(1.0f));
	}

	~TestSceneNode() 
	{
		delete model;
	}

	virtual void update()
	{
		mjt::SceneNode::update();
	}

	virtual void render()
	{
		model->render();

		mjt::SceneNode::render();
	}
};