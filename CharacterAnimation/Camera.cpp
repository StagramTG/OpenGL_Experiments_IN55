#include "Camera.h"

namespace mjt
{
	Camera::Camera(): m_settings()
	{
	}

	Camera::Camera(CameraSettings settings)
	{
		m_settings = settings;
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

	glm::mat4 Camera::getMatrix()
	{
		return m_projection * m_view;
	}
}
