#pragma once

#include <glm\vec3.hpp>

namespace mjt
{
	struct CameraSettings
	{
		/*Perspective settings*/
		float fov;
		float aspect;
		float znear;
		float zfar;

		glm::vec3 position;
		glm::vec3 target;

		/*Constructor to init default values*/
		CameraSettings() :
			fov(45.f),
			aspect(16.f/9.f),
			znear(0.1f),
			zfar(100.f)
		{}
	};
}