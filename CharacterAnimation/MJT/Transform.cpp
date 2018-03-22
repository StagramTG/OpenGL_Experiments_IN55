#include "Transform.h"

namespace mjt
{
	Transform::Transform()
	{
		m_position = glm::vec3(0.f, 0.f, 0.f);
		m_scale = glm::vec3(1.f, 1.f, 1.f);

		m_rotationX = 0.f;
		m_rotationY = 0.f;
		m_rotationZ = 0.f;

		m_fromWorld = glm::mat4(1.0f);

		calculateMatrix();
	}

	Transform::~Transform()
	{
	}

	glm::mat4 Transform::getToWorld()
	{
		calculateMatrix();
		return m_toWorld;
	}

	glm::mat4 Transform::getFromWorld()
	{
		return m_fromWorld;
	}

	glm::vec3 Transform::getPosition()
	{
		return m_position;
	}

	glm::vec3 Transform::getScale()
	{
		return m_scale;
	}

	float Transform::getRotationX()
	{
		return m_rotationX;
	}

	float Transform::getRotationY()
	{
		return m_rotationY;
	}

	float Transform::getRotationZ()
	{
		return m_rotationZ;
	}

	void Transform::setPosition(glm::vec3 position)
	{
		m_position = position;
	}

	void Transform::move(glm::vec3 movement)
	{
		m_position = m_position + movement;
	}

	void Transform::setScale(glm::vec3 scale)
	{
		m_scale = scale;
	}

	void Transform::setRotationX(float rotationX)
	{
		m_rotationX = rotationX;
	}

	void Transform::setRotationY(float rotationY)
	{
		m_rotationY = rotationY;
	}

	void Transform::setRotationZ(float rotationZ)
	{
		m_rotationZ = rotationZ;
	}

	void Transform::calculateMatrix()
	{
		m_toWorld = glm::mat4(1.0f);
		m_toWorld = glm::translate(m_toWorld, m_position) *
			glm::rotate(m_toWorld, m_rotationX, glm::vec3(1, 0, 0)) *
			glm::rotate(m_toWorld, m_rotationY, glm::vec3(0, 1, 0)) *
			glm::rotate(m_toWorld, m_rotationZ, glm::vec3(0, 0, 1)) *
			glm::scale(m_toWorld, m_scale);
	}
}