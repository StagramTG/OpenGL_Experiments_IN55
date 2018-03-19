#include "Entity.h"

namespace mjt
{
	Entity::Entity()
	{
	}

	Entity::~Entity()
	{
	}

	glm::mat4 Entity::getModelMatrix()
	{
		glm::mat4 model = glm::mat4(1.f);
		model = glm::translate(model, m_position) *
			glm::rotate(model, m_rotX, glm::vec3(1, 0, 0)) *
			glm::rotate(model, m_rotX, glm::vec3(0, 1, 0)) *
			glm::rotate(model, m_rotX, glm::vec3(0, 0, 1)) *
			glm::scale(model, m_scale);

		return model;
	}

	glm::vec3 Entity::getPosition()
	{
		return m_position;
	}

	glm::vec3 Entity::getScale()
	{
		return m_scale;
	}

	float Entity::getRotationX()
	{
		return m_rotX;
	}

	float Entity::getRotationY()
	{
		return m_rotY;
	}

	float Entity::getRotationZ()
	{
		return m_rotZ;
	}

	void Entity::setPosition(glm::vec3 position)
	{
		m_position = position;
	}

	void Entity::setPosition(float x, float y, float z)
	{
		setPosition(glm::vec3(x, y, z));
	}

	void Entity::setScale(glm::vec3 scale)
	{
		m_scale = scale;
	}

	void Entity::setScale(float sx, float sy, float sz)
	{
		setScale(glm::vec3(sx, sy, sz));
	}

	void Entity::setRotationX(float rotX)
	{
		m_rotX = rotX;
	}

	void Entity::setRotationY(float rotY)
	{
		m_rotY = rotY;
	}

	void Entity::setRotationZ(float rotZ)
	{
		m_rotZ = rotZ;
	}
}
