#pragma once

#include <SFML/Graphics.hpp>
#include <vector>

#include "GuiElement.h"
#include "../OrthoCamera.h"
#include "../ShaderProgram.h"

namespace mjt 
{
	namespace gui
	{
		class GuiManager
		{
		private:
			ShaderProgram * m_shader;
			std::vector<GuiElement*> m_elements;
			OrthoCamera* camera;

		public:
			GuiManager(int width, int height);
			~GuiManager();

			void update();
			void render();

			bool addElement(GuiElement* element);
			bool removeElement(GuiElement* element);
		};
	}
}