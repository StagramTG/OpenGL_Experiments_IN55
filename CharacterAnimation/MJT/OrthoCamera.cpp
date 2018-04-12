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
		(float)m_settings.left,
		(float)m_settings.right,
		(float)m_settings.bottom,
		(float)m_settings.top,
		-1.f,
		1.f
	);

	m_view = glm::lookAt(
		m_settings.position,
		m_settings.target,
		glm::vec3(0, 1, 0)
	);
}
