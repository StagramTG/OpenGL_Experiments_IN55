#include "OrthoCamera.h"

mjt::OrthoCamera::OrthoCamera(CameraSettings settings): Camera(settings)
{
}

mjt::OrthoCamera::~OrthoCamera()
{
}

void mjt::OrthoCamera::update()
{
	m_projection = glm::ortho(
		m_settings.left,
		m_settings.right,
		m_settings.bottom,
		m_settings.top
	);

	m_view = glm::lookAt(
		m_settings.position,
		m_settings.target,
		glm::vec3(0, 1, 0)
	);
}
