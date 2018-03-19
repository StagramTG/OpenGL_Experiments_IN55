#include "OglWindow.h"

OglWindow::OglWindow(int width, int height, const char* title):
	mjt::OglWindowAbs(width, height, title)
{
}

OglWindow::~OglWindow()
{
	delete mod;

	delete camera;
	delete texture;
}

void OglWindow::init()
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

	std::vector<GLfloat> data(vertices, vertices+9);
	std::vector<GLfloat> col(colors, colors+9);
	std::vector<GLuint> ind(index, index+3);

	mod = new mjt::ColoredModel(GL_TRIANGLES, data, col, ind);

	shader = new mjt::ShaderProgram();
	shader->init("shaders/vertex.glsl", "shaders/fragment.glsl");

	camera = new mjt::PerspectiveCamera(mjt::CameraSettings());
	camera->setPosition(glm::vec3(3.f, 3.f, 4.f));
	camera->update();

	model = glm::mat4(1.0f);
	model = glm::translate(model, glm::vec3(-2.f, 0, 0));

	texture = new mjt::Texture("images/tile.jpg");
}

void OglWindow::update()
{
}

void OglWindow::render()
{
	camera->update();
	model = glm::rotate(model, glm::radians(1.f), glm::vec3(0.f, 1.f, 0.f));

	shader->use();
	GLuint loc = shader->getUniformLocation("mvp");
	shader->setUniformMat4(loc, camera->getMatrix() * model);

	mod->render();

	shader->done();
}
