#pragma once

#include "MJT/SceneNode.h"
#include "MJT/ColoredModel.h"

class TestSceneNode : public mjt::SceneNode
{
private:
	mjt::ColoredModel* model;

public:
	TestSceneNode() : mjt::SceneNode()
	{
		GLfloat vertices[] = {
			-0.5f, 0.5f, 0.5f,
			0.5f, 0.5f, 0.5f,
			-0.5f, -0.5f, 0.5f,
			0.5f, -0.5f, 0.5f,

			-0.5f, 0.5f, -0.5f,
			0.5f, 0.5f, -0.5f,
			-0.5f, -0.5f, -0.5f,
			0.5f, -0.5f, -0.5f,
		};

		GLfloat colors[] = {
			1.f, 0.f, 0.f,
			0.f, 1.f, 0.f,
			0.f, 0.f, 1.f,
			1.f, 0.f, 0.f,
			0.f, 1.f, 0.f,
			0.f, 0.f, 1.f,
			1.f, 1.f, 1.f,
			1.f, 1.f, 1.f,
		};

		GLuint index[] = {
			0, 2, 1,
			2, 3, 1,

			4, 5, 7,
			7, 6, 4,

			4, 0, 5,
			0, 1, 5,

			1, 3, 5,
			3, 7, 5,

			4, 6, 2,
			2, 0, 4,

			3, 2, 6,
			3, 6, 7
		};

		std::vector<GLfloat> data(vertices, vertices + 24);
		std::vector<GLfloat> col(colors, colors + 24);
		std::vector<GLuint> ind(index, index + 36);

		model = new mjt::ColoredModel(GL_TRIANGLES, data, col, ind);
	}

	~TestSceneNode() 
	{
		delete model;
	}

	virtual void update()
	{
		m_transform->setRotationZ(m_transform->getRotationZ() + 0.01f);
		m_transform->setRotationX(m_transform->getRotationX() + 0.01f);

		mjt::SceneNode::update();
	}

	virtual void render()
	{
		model->render();

		mjt::SceneNode::render();
	}
};