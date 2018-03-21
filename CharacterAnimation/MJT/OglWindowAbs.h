#pragma once

#include <GL\glew.h>
#include <SFML\Graphics.hpp>
#include <iostream>

namespace mjt
{
	class OglWindowAbs
	{
	protected:
		sf::RenderWindow m_window;

		/*Methods*/
		void initWindow(int width, int height, const char* title);

	public:
		OglWindowAbs();
		OglWindowAbs(int width, int height, const char* title);
		~OglWindowAbs();

		virtual void init() = 0;
		virtual void update() = 0;
		virtual void render() = 0;

		void start();
	};
}
