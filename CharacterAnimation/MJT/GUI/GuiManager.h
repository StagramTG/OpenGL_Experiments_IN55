#pragma once

#include <SFML/Graphics.hpp>

namespace mjt 
{
	namespace gui
	{
		class GuiManager
		{
		private:
			sf::Font m_font;

		public:
			GuiManager();
			~GuiManager();

			void update();
			void render();
		};
	}
}