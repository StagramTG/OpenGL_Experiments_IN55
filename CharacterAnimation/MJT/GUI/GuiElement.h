#pragma once

#include <glm/gtc/matrix_transform.hpp>
#include "../SceneNode.h"

namespace mjt
{
	namespace gui
	{
		class GuiElement: public SceneNode
		{
		protected:

		public:
			GuiElement() {}
			~GuiElement() {}
		};
	}
}