#pragma once

#include "MJT/OglWindowAbs.h"
#include "MJT/ShaderProgram.h"
#include "MJT/PerspectiveCamera.h"
#include "MJT/Texture.h"

#include "TestSceneNode.h"

class OglWindow: public mjt::OglWindowAbs
{
private:
	TestSceneNode * testNode;

	mjt::ShaderProgram* shader;
	mjt::PerspectiveCamera* camera;

public:
	OglWindow(int width, int height, const char* title);
	~OglWindow();

	void init() override;
	void update() override;
	void render() override;
};

