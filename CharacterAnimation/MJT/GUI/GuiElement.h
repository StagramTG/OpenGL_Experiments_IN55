#pragma once

#include <glm/gtc/matrix_transform.hpp>

namespace mjt
{
	namespace gui
	{
		class GuiElement
		{
		protected:

		public:
			GuiElement() {}
			~GuiElement() {}

			virtual void update() = 0;
			virtual void render() = 0;
		};
	}
}