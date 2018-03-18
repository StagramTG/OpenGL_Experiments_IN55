#pragma once

#include <glm\gtc\matrix_transform.hpp>
#include "CameraSettings.h"

namespace mjt
{
	class Camera
	{
	protected:
		CameraSettings m_settings;

		glm::mat4 m_view;
		glm::mat4 m_projection;

	public:
		Camera();
		Camera(CameraSettings settings);
		~Camera();

		void setPosition(glm::vec3 position);
		glm::vec3 getPosition();

		void setTarget(glm::vec3 target);
		glm::vec3 getTarget();

		void move(glm::vec3 move);

		/*Method to implement to calculate view and projections matrices*/
		virtual void update() = 0;
		glm::mat4 getViewOf(glm::mat4 modelMat);
	};
}
