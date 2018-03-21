#pragma once

#include "MJT/OglWindowAbs.h"
#include "MJT/ShaderProgram.h"
#include "MJT/PerspectiveCamera.h"
#include "MJT/Texture.h"

#include "TestEntity.h"

class OglWindow: public mjt::OglWindowAbs
{
private:
	TestEntity* entity;

	mjt::ShaderProgram* shader;
	mjt::PerspectiveCamera* camera;

	mjt::Texture* texture;

public:
	OglWindow(int width, int height, const char* title);
	~OglWindow();

	void init() override;
	void update() override;
	void render() override;
};

