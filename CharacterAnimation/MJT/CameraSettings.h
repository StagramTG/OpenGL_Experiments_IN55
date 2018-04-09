#pragma once

#include <glm\vec3.hpp>

namespace mjt
{
	struct CameraSettings
	{
		/*Perspective settings*/
		float fov = 45.f;
		float aspect = 16.f / 9.f;
		float znear = 0.1f;
		float zfar = 100.f;

		glm::vec3 position = glm::vec3(0.f, 0.f, 0.f);
		glm::vec3 target = glm::vec3(0.f, 0.f, 0.f);

		unsigned int left = 0;
		unsigned int right = 854;
		unsigned int top = 0;
		unsigned int bottom = 480;
	};
}