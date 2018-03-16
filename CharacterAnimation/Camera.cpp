#include "Camera.h"

namespace mjt
{
	Camera::Camera()
	{
	}

	Camera::~Camera()
	{
	}

	void Camera::setPosition(glm::vec3 position)
	{
		m_position = position;
	}

	glm::vec3 Camera::getPosition()
	{
		return m_position;
	}

	void Camera::setTarget(glm::vec3 target)
	{
		m_target = target;
	}

	glm::vec3 Camera::getTarget()
	{
		return m_target;
	}

	void Camera::move(glm::vec3 move)
	{
		m_position += move;
	}
}
