#pragma once

#include <SFML/Graphics.hpp>
#include "GuiElement.h"

namespace mjt
{
	namespace gui
	{
		class Label: public GuiElement
		{
		private:
			sf::Text m_text;

		public:
			Label();
			~Label();

			void setString(std::string text);
			void setPosition(glm::vec2 position);

			virtual void update() override;
			virtual void render() override;
		};
	}
}