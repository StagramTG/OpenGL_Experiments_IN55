#include "PerspectiveCamera.h"
#include <iostream>

namespace mjt
{
	PerspectiveCamera::PerspectiveCamera(CameraSettings settings): Camera()
	{
		std::cout << "ZNEAR " << m_settings.znear << std::endl;
		std::cout << "ZFAR " << m_settings.zfar << std::endl;
	}

	PerspectiveCamera::~PerspectiveCamera()
	{
	}

	void PerspectiveCamera::update()
	{
		m_view = glm::lookAt(
			m_settings.position,
			m_settings.target,
			glm::vec3(0, 1, 0)
		);

		m_projection = glm::perspective(
			glm::radians(m_settings.fov),
			m_settings.aspect,
			m_settings.znear,
			m_settings.zfar
		);
	}
}
