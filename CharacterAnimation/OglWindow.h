#pragma once

#include "TestScene.h"

class OglWindow: public mjt::OglWindowAbs
{
private:
	TestScene * testScene;

public:
	OglWindow(int width, int height, const char* title);
	~OglWindow();

	void init() override;
};

