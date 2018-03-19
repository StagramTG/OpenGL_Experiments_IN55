#include "TestEntity.h"

TestEntity::TestEntity(): mjt::Entity()
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
}

TestEntity::~TestEntity()
{
	delete model;
}

void TestEntity::update()
{
	setRotationY(m_rotY + 0.01f);
}

void TestEntity::render()
{
	model->render();
}
