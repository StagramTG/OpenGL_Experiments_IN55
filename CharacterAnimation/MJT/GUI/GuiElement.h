#pragma once

#include <glm/gtc/matrix_transform.hpp>

namespace mjt
{
	namespace gui
	{
		class GuiElement
		{
		protected:
			glm::vec3 m_position;

		public:
			GuiElement() {}
			~GuiElement() {}

			virtual void update() = 0;
			virtual void render() = 0;
		};
	}
}