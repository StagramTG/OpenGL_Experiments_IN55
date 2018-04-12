#pragma once

#include <GL/glew.h>
#include <vector>

namespace mjt
{
	namespace utils
	{
		class MeshUtils
		{
		public:
			// Create a square model composed of 4 vertices
			static std::vector<GLfloat> createSquare(int x, int y, int width, int height);
		};
	}
}