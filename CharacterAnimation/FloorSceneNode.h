#pragma once

#include "MJT\SceneNode.h"
#include "MJT\TexturedModel.h"

class FloorSceneNode: public mjt::SceneNode
{
private:
	mjt::TexturedModel* model;

public:
	FloorSceneNode(): mjt::SceneNode()
	{
		GLfloat vert[] = {
			-0.5f, 0.f, 0.5f,
			0.5f, 0.f, 0.5f,
			-0.5f, 0.f, -0.5f,
			0.5f, 0.f, -0.5f,
		};

		GLfloat tex[] = {
			0.f, 0.f,
			3.f, 0.f,
			0.f, 3.f,
			3.f, 3.f,
		};

		GLuint ind[] = {
			0, 1, 2,
			1, 3, 2
		};

		std::vector<GLfloat> data(vert, vert + 12);
		std::vector<GLfloat> uvs(tex, vert + 8);
		std::vector<GLuint> indices(ind, ind + 6);

		model = new mjt::TexturedModel(
			GL_TRIANGLES,
			data,
			uvs,
			indices,
			"Assets/Images/dirt.png"
		);

		m_transform->setPosition(glm::vec3(0, -0.5f, 0));
		m_transform->setScale(glm::vec3(3, 3, 3));
	}

	~FloorSceneNode()
	{
		delete model;

		mjt::SceneNode::update();
	}

	void render(mjt::ShaderProgram* shader, mjt::Camera* camera) override
	{
		GLuint mvp = shader->getUniformLocation("mvp");
		shader->setUniformMat4(mvp, camera->getMatrix() * m_transform->getToWorld());
		model->render();

		mjt::SceneNode::render(shader, camera);
	}
};