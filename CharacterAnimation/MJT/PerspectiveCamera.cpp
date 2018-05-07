#include "PerspectiveCamera.h"
#include <iostream>

namespace mjt
{
	PerspectiveCamera::PerspectiveCamera(CameraSettings settings): Camera(settings)
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
			m_settings.up
		);

		m_projection = glm::perspective(
			glm::radians(m_settings.fov),
			m_settings.aspect,
			m_settings.znear,
			m_settings.zfar
		);
	}
}
