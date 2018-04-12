#pragma once

#include <GL/glew.h>
#include <vector>

namespace mjt
{
	namespace utils
	{
		struct MeshData
		{
			std::vector<GLfloat> vertices;
			std::vector<GLfloat> uvs;
			std::vector<GLint> indices;
		};

		class MeshUtils
		{
		public:
			// Create a square model composed of 4 vertices
			static MeshData createSquare(
				GLfloat x, GLfloat y, GLfloat width, GLfloat height,
				GLfloat texX = 0, GLfloat texY = 0, GLfloat texWidth = 1, GLfloat texHeight = 1
			);
		};
	}
}