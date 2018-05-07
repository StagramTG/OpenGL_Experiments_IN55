#pragma once

#include <GL\glew.h>
#include <SFML\Graphics.hpp>
#include <iostream>
#include <vector>

#include "Scene.h"

namespace mjt
{
	class OglWindowAbs
	{
	protected:
		sf::RenderWindow m_window;
		std::vector<Scene*> m_scenes;
		Scene* m_activeScene;
		sf::Vector2i lastMousePosition = sf::Vector2i(0, 0);

		/*Methods*/
		void initWindow(int width, int height, const char* title);

	public:
		OglWindowAbs();
		OglWindowAbs(int width, int height, const char* title);
		~OglWindowAbs();

		virtual void init() = 0;

		void start();

		/*Scene managment methods*/
		bool addScene(Scene* scene);
		bool setActiveScene(const char* name);
		bool deleteScene(const char* name);
	};
}
