#include "MeshUtils.h"

mjt::utils::MeshData mjt::utils::MeshUtils::createSquare(GLfloat x, GLfloat y, GLfloat width, GLfloat height, 
	GLfloat texX, GLfloat texY, GLfloat texWidth, GLfloat texHeight)
{
	GLfloat v[] = {
		x, y, 0,
		x + width, y, 0,
		x, y + height, 0,
		x + width, y + height, 0
	};
	std::vector<GLfloat> vertices(v, v + 12);

	GLfloat u[] = {
		texX, texY,
		texX + texWidth, texY,
		texX, texY + texHeight,
		texX + texWidth, texY + texHeight
	};
	std::vector<GLfloat> uvs(u, u + 8);

	GLint i[] = {
		0, 1, 2,
		1, 3, 2
	};
	std::vector<GLint> indices(i, i + 6);

	mjt::utils::MeshData meshData = {
		vertices,
		uvs,
		indices
	};

	return meshData;
}
