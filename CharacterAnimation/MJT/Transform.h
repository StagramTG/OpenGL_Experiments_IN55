#pragma once

#include <glm/gtc/matrix_transform.hpp>

namespace mjt
{
	class Transform
	{
	private:
		glm::mat4 m_toWorld, m_fromWorld;
		glm::vec3 m_position, m_scale;
		float m_rotationX, m_rotationY, m_rotationZ;

		void calculateMatrix();

	public:
		Transform();
		~Transform();

		glm::mat4 getToWorld();
		glm::mat4 getFromWorld();
		glm::vec3 getPosition();
		glm::vec3 getScale();
		float getRotationX();
		float getRotationY();
		float getRotationZ();

		void setPosition(glm::vec3 position);
		void move(glm::vec3 movement);
		void setScale(glm::vec3 scale);
		void setRotationX(float rotationX);
		void setRotationY(float rotationY);
		void setRotationZ(float rotationZ);
	};
}