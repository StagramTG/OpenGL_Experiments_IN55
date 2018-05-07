#include "Camera.h"

namespace mjt
{

	const float SENSITIVITY = 0.1f;

	Camera::Camera() : m_settings()
	{
	}

	Camera::Camera(CameraSettings settings)
	{
		m_settings = settings;
		updateCameraVect();
	}

	Camera::~Camera()
	{
	}

	void Camera::setPosition(glm::vec3 position)
	{
		m_settings.position = position;
		updateCameraVect();
	}

	glm::vec3 Camera::getPosition()
	{
		return m_settings.position;
	}

	void Camera::setTarget(glm::vec3 target)
	{
		m_settings.target = target;

		//Mise à jour de l'orientation selon la nouvelle cible
		m_settings.orientation = glm::normalize(m_settings.target - m_settings.position);

		//Mise à jour des angles
		m_settings.phi = glm::degrees(asin(m_settings.orientation.y));
		m_settings.theta = glm::degrees(acos(m_settings.orientation.z / cos(glm::radians(m_settings.phi))));

		if (m_settings.orientation.z < 0)
			m_settings.theta *= -1;

		m_settings.lateralMovement = glm::normalize(glm::cross(m_settings.orientation, m_settings.verticalAxe));
		m_settings.up = glm::normalize(glm::cross(m_settings.lateralMovement, m_settings.orientation));
	}

	glm::vec3 Camera::getTarget()
	{
		return m_settings.target;
	}

	float Camera::getSensitivity()
	{
		return m_settings.sensitivity;
	}

	void Camera::setSensitivity(float sensitivity)
	{
		m_settings.sensitivity = sensitivity;
	}

	float Camera::getSpeed()
	{
		return m_settings.speed;
	}

	void Camera::setSpeed(float speed)
	{
		m_settings.speed = speed;
	}

	void Camera::move(glm::vec3 move)
	{
		m_settings.position += move;
	}

	void Camera::move(sf::Keyboard::Key input)
	{
		// Avancée de la caméra
		if (input == sf::Keyboard::Up)
			m_settings.position += m_settings.orientation * m_settings.speed;


		// Recul de la caméra
		if (input == sf::Keyboard::Down)
			m_settings.position -= m_settings.orientation * m_settings.speed;


		// Déplacement vers la gauche
		if (input == sf::Keyboard::Left)
			m_settings.position += m_settings.lateralMovement * m_settings.speed;


		// Déplacement vers la droite
		if (input == sf::Keyboard::Right)
			m_settings.position -= m_settings.lateralMovement * m_settings.speed;

		m_settings.target = m_settings.position + m_settings.orientation;
	}

	void Camera::move(int x, int y)
	{
		//Mise à jour des angles
		m_settings.phi += y * m_settings.sensitivity;
		m_settings.theta += x * m_settings.sensitivity;


		if (m_settings.phi > 89.0f)
			m_settings.phi = 89.0f;

		else if (m_settings.phi < -89.0f)
			m_settings.phi = -89.0f;

		//Mise à jour orientation
		updateCameraVect();
	}

	glm::mat4 Camera::getMatrix()
	{
		return m_projection * m_view;
	}

	void Camera::updateCameraVect()
	{
		m_settings.orientation.x = sin(glm::radians(m_settings.theta)) * cos(glm::radians(m_settings.phi));
		m_settings.orientation.y = sin(glm::radians(m_settings.phi));
		m_settings.orientation.z = cos(glm::radians(m_settings.theta)) * cos(glm::radians(m_settings.phi));
		m_settings.orientation = glm::normalize(m_settings.orientation);

		m_settings.lateralMovement = glm::normalize(glm::cross(m_settings.orientation, m_settings.verticalAxe));  // Normalize the vectors, because their length gets closer to 0 the more you look up or down which results in slower movement.
		m_settings.up = glm::normalize(glm::cross(m_settings.lateralMovement, m_settings.orientation));

		m_settings.target = m_settings.position + m_settings.orientation;
	}
}
