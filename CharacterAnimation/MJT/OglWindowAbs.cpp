#include "OglWindowAbs.h"

namespace mjt
{
	void OglWindowAbs::initWindow(int width, int height, const char * title)
	{
		sf::ContextSettings settings;
		settings.majorVersion = 3;
		settings.minorVersion = 3;

		m_window.create(sf::VideoMode(width, height), title);
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
		glEnable(GL_DEPTH_TEST);
		glEnable(GL_CULL_FACE);
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

			update();

			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			render();
			m_window.display();
		}
	}
}
