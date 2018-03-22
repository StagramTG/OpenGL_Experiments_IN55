#pragma once

#include <vector>
#include "Transform.h"

namespace mjt
{
	class SceneNode
	{
	protected:
		SceneNode* m_parent;
		std::vector<SceneNode*> m_children;
		Transform* m_transform;

	public:
		SceneNode();
		~SceneNode();
	};
}
