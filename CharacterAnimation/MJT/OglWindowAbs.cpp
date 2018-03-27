#include "OglWindowAbs.h"

namespace mjt
{
	void OglWindowAbs::initWindow(int width, int height, const char * title)
	{
		sf::ContextSettings settings;
		settings.majorVersion	   = 3;
		settings.minorVersion	   = 3;
		settings.depthBits         = 24;
		settings.stencilBits       = 8;
        settings.antialiasingLevel = 2;

		m_window.create(sf::VideoMode(width, height), title, sf::Style::Default, settings);
		m_window.setVerticalSyncEnabled(true);
		m_window.setActive(true);

		/*Init GLEW*/
		glewExperimental = true;
		GLenum success = glewInit();
		if (success != GLEW_OK)
		{
			std::cerr << "Glew initialization failed..." << std::endl;
		}

		/*Enable OpenGL things*/
		glEnable(GL_TEXTURE_2D);

		glDepthFunc(GL_LESS);
		glEnable(GL_DEPTH_TEST);

		glEnable(GL_CULL_FACE);
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glCullFace(GL_BACK);
	}

	OglWindowAbs::OglWindowAbs()
	{
		initWindow(1280, 720, "OGL MJT");
	}

	OglWindowAbs::OglWindowAbs(int width, int height, const char * title)
	{
		initWindow(width, height, title);
	}

	OglWindowAbs::~OglWindowAbs()
	{
	}

	void OglWindowAbs::start()
	{
		init();

		while (m_window.isOpen())
		{
			sf::Event event;
			while (m_window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					m_window.close();
			}

			if (m_activeScene != nullptr)
				m_activeScene->update();

			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			
			if (m_activeScene != nullptr)
				m_activeScene->render(nullptr, nullptr);

			m_window.display();
		}
	}

	bool OglWindowAbs::addScene(Scene * scene)
	{
		for (size_t i = 0; i < m_scenes.size(); ++i)
		{
			if (m_scenes[i]->getName() == scene->getName())
			{
				return false;
			}
		}

		m_scenes.push_back(scene);
		return true;
	}

	bool OglWindowAbs::setActiveScene(const char * name)
	{
		for (size_t i = 0; i < m_scenes.size(); ++i)
		{
			if (m_scenes[i]->getName() == name)
			{
				m_activeScene = m_scenes[i];
				m_activeScene->init();
				return true;
			}
		}

		return false;
	}

	bool OglWindowAbs::deleteScene(const char * name)
	{
		if (m_activeScene->getName() == name)
		{
			return false;
		}

		for (size_t i = 0; i < m_scenes.size(); ++i)
		{
			if (m_scenes[i]->getName() == name)
			{
				m_scenes.erase(m_scenes.begin() + i);
				return true;
			}
		}

		return false;
	}
}
