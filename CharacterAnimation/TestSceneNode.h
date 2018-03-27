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
			// front
			-1.0, -1.0,  1.0,
			 1.0, -1.0,  1.0,
			 1.0,  1.0,  1.0,
			-1.0,  1.0,  1.0,
			// back
			-1.0, -1.0, -1.0,
			 1.0, -1.0, -1.0,
			 1.0,  1.0, -1.0,
			-1.0,  1.0, -1.0,
		};

		GLfloat colors[] = {
			0, 0,
			1, 0,
			1, 1,
			0, 1,

			0, 0,
			1, 0,
			1, 1,
			0, 1,
		};

		GLuint index[] = {
			// front
			0, 1, 2,
			2, 3, 0,
			// right
			1, 5, 6,
			6, 2, 1,
			// back
			7, 6, 5,
			5, 4, 7,
			// left
			4, 0, 3,
			3, 7, 4,
			// bottom
			4, 5, 1,
			1, 0, 4,
			// top
			3, 2, 6,
			6, 7, 3,
		};

		std::vector<GLfloat> data(vertices, vertices + 24);
		std::vector<GLfloat> col(colors, colors + 16);
		std::vector<GLuint> ind(index, index + 36);

		model = new mjt::TexturedModel(GL_TRIANGLES, data, col, ind, "Assets/Images/stone.png");
		m_transform->setScale(glm::vec3(0.5f));
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