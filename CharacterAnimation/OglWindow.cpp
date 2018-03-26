#include "OglWindow.h"

OglWindow::OglWindow(int width, int height, const char* title):
	mjt::OglWindowAbs(width, height, title)
{
}

OglWindow::~OglWindow()
{
	delete testNode;
	delete floorNode;

	delete shader;
	delete camera;
}

void OglWindow::init()
{
	testNode = new TestSceneNode();
	floorNode = new FloorSceneNode();

	shader = new mjt::ShaderProgram();
	shader->init("Assets/Shaders/vertex.glsl", "Assets/Shaders/fragment.glsl");

	camera = new mjt::PerspectiveCamera(mjt::CameraSettings());
	camera->setPosition(glm::vec3(3.f, 3.f, 4.f));
}

void OglWindow::update()
{
	testNode->update();
	camera->update();
}

void OglWindow::render()
{
	shader->use();
	GLuint loc = shader->getUniformLocation("mvp");

	shader->setUniformMat4(loc, camera->getMatrix() * floorNode->getTransform()->getToWorld());
	floorNode->render();

	shader->setUniformMat4(loc, camera->getMatrix() * testNode->getTransform()->getToWorld());
	testNode->render();

	shader->done();
}
