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

	m_view = glm::mat4(1.0);
}
