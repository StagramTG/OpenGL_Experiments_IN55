#pragma once

/*Shared_ptr*/
#include <memory>
#include <vector>

namespace mjt
{
	class SceneNode
	{
	protected:
		SceneNode* m_parent;
		std::vector<SceneNode*> m_children;

	public:
		SceneNode();
		~SceneNode();
	};
}
