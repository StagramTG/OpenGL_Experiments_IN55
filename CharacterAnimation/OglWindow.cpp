#include "OglWindow.h"

OglWindow::OglWindow(int width, int height, const char* title):
	mjt::OglWindowAbs(width, height, title)
{
}

OglWindow::~OglWindow()
{
	delete vbo;
	delete vao;
}

void OglWindow::init()
{
	GLfloat vertices[] = {
		0.f, 1.f, 0.f,
		1.f, -1.f, 0.f,
		-1.f, -1.f, 0.f,
	};

	std::vector<GLfloat> data(vertices, vertices+12);

	vao = new mjt::VertexArrayObject();
	vao->bind();
	vao->enableAttribArray(0);

	vbo = new mjt::VertexBufferObject();
	vbo->bind();
	vbo->setData(data);
	
	vao->attribPointer(0, 3, GL_FLOAT, GL_FALSE, 0);
	
	vao->unbind();

	shader = new mjt::ShaderProgram();
	shader->init("shaders/vertex.glsl", "shaders/fragment.glsl");
}

void OglWindow::update()
{
}

void OglWindow::render()
{
	shader->use();

	vao->bind();
	glDrawArrays(GL_TRIANGLES, 0, 3);
	vao->unbind();
}
