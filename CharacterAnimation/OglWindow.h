#pragma once

#include "OglWindowAbs.h"
#include "VertexArrayObject.h"
#include "VertexBufferObject.h"
#include "ShaderProgram.h"
#include "PerspectiveCamera.h"
#include "IndicesBufferObject.h"

class OglWindow: public mjt::OglWindowAbs
{
private:
	mjt::VertexArrayObject* vao;
	mjt::VertexBufferObject* vbo;
	mjt::VertexBufferObject* vbocolors;
	mjt::IndicesBufferObject* indices;

	mjt::ShaderProgram* shader;
	mjt::PerspectiveCamera* camera;

	glm::mat4 model;

	sf::Texture* texture;

public:
	OglWindow(int width, int height, const char* title);
	~OglWindow();

	void init() override;
	void update() override;
	void render() override;
};

