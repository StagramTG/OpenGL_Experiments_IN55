#include "Entity.h"

namespace mjt
{
	Entity::Entity()
	{
		m_modelMatrix = glm::mat4(1.f);
	}

	Entity::~Entity()
	{
	}
}
