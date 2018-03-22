#include "SceneNode.h"

namespace mjt
{
	SceneNode::SceneNode()
	{
		m_transform = new Transform();
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

	void SceneNode::update()
	{
		for (SceneNode* child : m_children)
		{
			child->update();
		}
	}

	void SceneNode::render()
	{
		for (SceneNode* child : m_children)
		{
			child->update();
		}
	}

	void SceneNode::addChild(SceneNode * child)
	{
		if (child != nullptr)
		{
			m_children.push_back(child);
		}
	}

	void SceneNode::removeChild(SceneNode * child)
	{
		for (size_t i = 0; i < m_children.size(); ++i)
		{
			if (m_children[i] == child)
			{
				m_children.erase(m_children.begin() + i);

				std::cout << "delete : " << child << std::endl;

				break;
			}
		}
	}
}
