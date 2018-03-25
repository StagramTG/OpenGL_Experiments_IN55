#include "OglWindow.h"

OglWindow::OglWindow(int width, int height, const char* title):
	mjt::OglWindowAbs(width, height, title)
{
}

OglWindow::~OglWindow()
{
	delete testScene;
}

void OglWindow::init()
{
	testScene = new TestScene();
	addScene(testScene);
	bool success = setActiveScene("Main");
	if (!success)
	{
		std::cerr << "No scene named Main" << std::endl;
	}
}
