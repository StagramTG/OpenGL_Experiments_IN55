#include "Transform.h"

namespace mjt
{
	Transform::Transform()
	{
	}

	Transform::~Transform()
	{
	}

	glm::mat4 Transform::getToWorld()
	{
		return glm::mat4();
	}

	glm::mat4 Transform::getFromWorld()
	{
		return glm::mat4();
	}

	glm::vec3 Transform::getPosition()
	{
		return glm::vec3();
	}

	glm::vec3 Transform::getScale()
	{
		return glm::vec3();
	}

	float Transform::getRotationX()
	{
		return 0.0f;
	}

	float Transform::getRotationY()
	{
		return 0.0f;
	}

	float Transform::getRotationZ()
	{
		return 0.0f;
	}
}