#pragma once

#include <iostream>

#include "MJT/SceneNode.h"
#include "MJT/TexturedModel.h"

class TestSceneNode : public mjt::SceneNode
{
private:
	mjt::TexturedModel* model;

public:
	TestSceneNode()
	{
		GLfloat vertices[] = {
			0.f, 1.f, 0.f,
			1.f, -1.f, 0.f,
			-1.f, -1.f, 0.f,
		};

		GLfloat colors[] = {
			0.5f, 0.f,
			-1.f, 1.f,
			1.f, 1.f
		};

		GLuint index[] = {
			0, 1, 2
		};

		std::vector<GLfloat> data(vertices, vertices + 9);
		std::vector<GLfloat> col(colors, colors + 6);
		std::vector<GLuint> ind(index, index + 3);

		model = new mjt::TexturedModel(GL_TRIANGLES, data, col, ind, "Assets/Images/stone.png");
	}

	~TestSceneNode() 
	{
		delete model;
	}

	virtual void update()
	{
		m_transform->setRotationY(m_transform->getRotationY() + 0.01f);

		mjt::SceneNode::update();
	}

	virtual void render(mjt::ShaderProgram* shader, mjt::Camera* camera)
	{
		GLuint loc = shader->getUniformLocation("mvp");
		shader->setUniformMat4(loc, camera->getMatrix() * m_transform->getToWorld());

		model->render();

		mjt::SceneNode::render(shader, camera);
	}
};