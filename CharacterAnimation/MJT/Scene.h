#pragma once

#include "SceneNode.h"

namespace mjt
{
	class Scene
	{
	protected:
		SceneNode * m_rootNode;

	public:
		Scene();
		~Scene();

		virtual void init() = 0;
		virtual void update();
		virtual void render();
	};
}
