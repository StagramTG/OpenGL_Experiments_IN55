#include "OglWindow.h"

OglWindow::OglWindow(int width, int height, const char* title):
	mjt::OglWindowAbs(width, height, title)
{
}

OglWindow::~OglWindow()
{
	delete entity;

	delete camera;
	delete texture;
}

void OglWindow::init()
{
	entity = new TestEntity();

	shader = new mjt::ShaderProgram();
	shader->init("shaders/vertex.glsl", "shaders/fragment.glsl");

	camera = new mjt::PerspectiveCamera(mjt::CameraSettings());
	camera->setPosition(glm::vec3(3.f, 3.f, 4.f));
	camera->update();

	texture = new mjt::Texture("images/tile.jpg");
}

void OglWindow::update()
{
	camera->update();
	entity->update();
}

void OglWindow::render()
{
	shader->use();
	GLuint loc = shader->getUniformLocation("mvp");
	shader->setUniformMat4(loc, camera->getMatrix() * entity->getModelMatrix());

	entity->render();

	shader->done();
}
