#include "OglWindow.h"

OglWindow::OglWindow(int width, int height, const char* title):
	mjt::OglWindowAbs(width, height, title)
{
}

OglWindow::~OglWindow()
{
	delete entity;
	delete root;

	delete camera;
	delete texture;
}

void OglWindow::init()
{
	entity = new TestEntity();

	shader = new mjt::ShaderProgram();
	shader->init("Assets/Shaders/vertex.glsl", "Assets/Shaders/fragment.glsl");

	camera = new mjt::PerspectiveCamera(mjt::CameraSettings());
	camera->setPosition(glm::vec3(3.f, 3.f, 4.f));
	camera->update();

	texture = new mjt::Texture("Assets/Images/tile.jpg");

	root = new mjt::SceneNode();
	mjt::SceneNode* child1 = new mjt::SceneNode();
	mjt::SceneNode* child2 = new mjt::SceneNode();

	root->addChild(child1);
	root->addChild(child2);

	root->removeChild(child2);
}

void OglWindow::update()
{
	camera->update();
	entity->update();

	root->update();
}

void OglWindow::render()
{
	shader->use();
	GLuint loc = shader->getUniformLocation("mvp");
	shader->setUniformMat4(loc, camera->getMatrix() * entity->getModelMatrix());

	entity->render();

	shader->done();
}
