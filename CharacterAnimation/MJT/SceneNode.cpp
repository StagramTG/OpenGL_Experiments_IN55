#include "SceneNode.h"

namespace mjt
{
	SceneNode::SceneNode()
	{
	}

	SceneNode::~SceneNode()
	{
		delete m_transform;

		/*Delete all children*/
		for (SceneNode* child : m_children)
		{
			delete child;
		}
	}
}
