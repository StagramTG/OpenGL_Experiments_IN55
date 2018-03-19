#include "OglWindow.h"

OglWindow::OglWindow(int width, int height, const char* title):
	mjt::OglWindowAbs(width, height, title)
{
}

OglWindow::~OglWindow()
{
	delete vbo;
	delete vbocolors;
	delete indices;
	delete vao;

	delete camera;
}

void OglWindow::init()
{
	GLfloat vertices[] = {
		0.f, 1.f, 0.f,
		1.f, -1.f, 0.f,
		-1.f, -1.f, 0.f,
	};

	GLfloat colors[] = {
		0.f, 1.f, 0.f,
		1.f, 0.f, 0.f,
		0.f, 0.f, 1.f,
	};

	GLuint index[] = {
		0, 1, 2
	};

	std::vector<GLfloat> data(vertices, vertices+9);
	std::vector<GLfloat> col(colors, colors+9);
	std::vector<GLuint> ind(index, index+9);

	vao = new mjt::VertexArrayObject();
	vao->bind();
	vao->enableAttribArray(0);

	vbo = new mjt::VertexBufferObject();
	vbo->bind();
	vbo->setData(data);
	
	vao->attribPointer(0, 3, GL_FLOAT, GL_FALSE, 0);
	vbo->unbind();

	vao->enableAttribArray(1);

	vbocolors = new mjt::VertexBufferObject();
	vbocolors->bind();
	vbocolors->setData(col);

	vao->attribPointer(1, 3, GL_FLOAT, GL_FALSE, 0);
	vbo->unbind();

	indices = new mjt::IndicesBufferObject();
	indices->bind();
	indices->setData(ind);

	vao->unbind();

	shader = new mjt::ShaderProgram();
	shader->init("shaders/vertex.glsl", "shaders/fragment.glsl");

	camera = new mjt::PerspectiveCamera(mjt::CameraSettings());
	camera->setPosition(glm::vec3(3.f, 3.f, 4.f));
	camera->update();

	model = glm::mat4(1.0f);
	model = glm::translate(model, glm::vec3(-2.f, 0, 0));
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

	vao->bind();
	glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, 0);
	vao->unbind();

	shader->done();
}
