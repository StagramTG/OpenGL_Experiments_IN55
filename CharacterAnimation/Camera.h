#pragma once

#include <glm\gtc\matrix_transform.hpp>
#include "CameraSettings.h"

namespace mjt
{
	class Camera
	{
	protected:
		glm::vec3 m_position;
		glm::vec3 m_target;

		glm::mat4 m_view;
		glm::mat4 m_projection;

		/*Methods*/
		void init(glm::vec3 position, glm::vec3 target);

	public:
		Camera();
		Camera(glm::vec3 position, glm::vec3 target);
		~Camera();

		void setPosition(glm::vec3 position);
		glm::vec3 getPosition();

		void setTarget(glm::vec3 target);
		glm::vec3 getTarget();

		void move(glm::vec3 move);

		virtual void update() = 0;
		glm::mat4 getViewOf(glm::mat4 modelMat);
	};
}
