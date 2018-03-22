#pragma once

#include "SceneNode.h"

namespace mjt
{
	class Scene
	{
	protected:

	public:
		Scene();
		~Scene();

		virtual void init();
		virtual void update();
		virtual void render();
	};
}
