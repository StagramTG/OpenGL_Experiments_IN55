#pragma once

#include <glm/mat4x4.hpp>

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
		glm::mat4 m_modelMatrix;

	public:
		Entity();
		~Entity();

		virtual void update() = 0;
		virtual void render() = 0;
	};
}
