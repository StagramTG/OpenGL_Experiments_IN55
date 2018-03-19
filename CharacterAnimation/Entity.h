#pragma once

#include <glm/gtc/matrix_transform.hpp>

namespace mjt
{
	/*
		Class Entity.
		Base class to all entity that regroup all component
		that compose a logical and displayable element.
	*/
	class Entity
	{
	private:
		glm::vec3 m_position;
		glm::vec3 m_scale;
		float m_rotX;
		float m_rotY;
		float m_rotZ;

	public:
		Entity();
		~Entity();

		virtual void update() = 0;
		virtual void render() = 0;

		glm::mat4 getModelMatrix();
		glm::vec3 getPosition();
		glm::vec3 getScale();
		float getRotationX();
		float getRotationY();
		float getRotationZ();

		void setPosition(glm::vec3 position);
		void setPosition(float x, float y, float z);
		void setScale(glm::vec3 scale);
		void setScale(float sx, float sy, float sz);
		void setRotationX(float rotX);
		void setRotationY(float rotY);
		void setRotationZ(float rotZ);
	};
}
