#pragma once

#include <vector>
#include "Transform.h"
#include "ShaderProgram.h"
#include "Camera.h"

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
		virtual ~SceneNode();

		virtual void update();
		virtual void render(ShaderProgram* shader, Camera* camera);

		void addChild(SceneNode* child);
		void removeChild(SceneNode* child);

		Transform* getTransform();
	};
}
