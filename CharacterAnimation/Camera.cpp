#include "Camera.h"

namespace mjt
{
	void Camera::init(glm::vec3 position, glm::vec3 target)
	{
		m_settings.position = position;
		m_settings.target = target;
	}

	Camera::Camera()
	{
		init(glm::vec3(), glm::vec3());
	}

	Camera::Camera(glm::vec3 position, glm::vec3 target)
	{
		init(position, target);
	}

	Camera::~Camera()
	{
	}

	void Camera::setPosition(glm::vec3 position)
	{
		m_settings.position = position;
	}

	glm::vec3 Camera::getPosition()
	{
		return m_settings.position;
	}

	void Camera::setTarget(glm::vec3 target)
	{
		m_settings.target = target;
	}

	glm::vec3 Camera::getTarget()
	{
		return m_settings.target;
	}

	void Camera::move(glm::vec3 move)
	{
		m_settings.position += move;
	}

	glm::mat4 Camera::getViewOf(glm::mat4 modelMat)
	{
		return m_projection * m_view * modelMat;
	}
}
