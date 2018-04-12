#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "GuiElement.h"

namespace mjt 
{
	namespace gui
	{
		class GuiManager
		{
		private:
			std::vector<GuiElement*> elements;

		public:
			GuiManager();
			~GuiManager();

			void update();
			void render();

			bool addElement(GuiElement* element);
			bool removeElement(GuiElement* element);
		};
	}
}