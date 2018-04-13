#include "MeshUtils.h"

mjt::utils::MeshData mjt::utils::MeshUtils::createSquare(GLfloat x, GLfloat y, GLfloat width, GLfloat height, 
	GLfloat texX, GLfloat texY, GLfloat texWidth, GLfloat texHeight, int indiceOffset)
{
	GLfloat v[] = {
		x, y, 0,
		x + width, y, 0,
		x, y + height, 0,
		x + width, y + height, 0
	};
	std::vector<GLfloat> vertices(v, v + 12);

	GLfloat u[] = {
		texX, 1 - texY,
		texX + texWidth, 1 - texY,
		texX, 1 - texY + texHeight,
		texX + texWidth, 1 - texY + texHeight
	};
	std::vector<GLfloat> uvs(u, u + 8);

	GLint i[] = {
		indiceOffset + 0, indiceOffset + 1, indiceOffset + 2,
		indiceOffset + 1, indiceOffset + 3, indiceOffset + 2
	};
	std::vector<GLint> indices(i, i + 6);

	mjt::utils::MeshData meshData = {
		vertices,
		uvs,
		indices
	};

	return meshData;
}
