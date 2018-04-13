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
			GuiElement(): SceneNode() {}
			~GuiElement() {}

			virtual void update() override { SceneNode::update(); }
			virtual void render(ShaderProgram* shader, Camera* camera) override { SceneNode::render(shader, camera); }
		};
	}
}