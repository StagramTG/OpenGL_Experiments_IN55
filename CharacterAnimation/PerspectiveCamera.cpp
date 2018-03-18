#include "PerspectiveCamera.h"

namespace mjt
{
	PerspectiveCamera::PerspectiveCamera(CameraSettings settings): Camera()
	{
	}

	PerspectiveCamera::~PerspectiveCamera()
	{
	}

	void PerspectiveCamera::update()
	{
		m_view = glm::lookAt(
			m_settings.position,
			m_settings.target,
			glm::vec3(0, 1.f, 0)
		);

		m_projection = glm::perspective(
			m_settings.fov,
			m_settings.aspect,
			m_settings.znear,
			m_settings.zfar
		);
	}
}
