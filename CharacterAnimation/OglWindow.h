#pragma once

#include "OglWindowAbs.h"
#include "ShaderProgram.h"
#include "PerspectiveCamera.h"
#include "Texture.h"

#include "ColoredModel.h"

class OglWindow: public mjt::OglWindowAbs
{
private:
	mjt::ColoredModel* mod;

	mjt::ShaderProgram* shader;
	mjt::PerspectiveCamera* camera;

	glm::mat4 model;

	mjt::Texture* texture;

public:
	OglWindow(int width, int height, const char* title);
	~OglWindow();

	void init() override;
	void update() override;
	void render() override;
};

