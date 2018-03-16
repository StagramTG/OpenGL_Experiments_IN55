#pragma once

#include <GL\glew.h>
#include <fstream>
#include <string>
#include <iostream>

#include <glm/gtc/matrix_transform.hpp>

namespace mjt
{
	class ShaderProgram
	{
	private:
		GLuint m_id;

	public:
		ShaderProgram();
		~ShaderProgram();

		bool init(const char* vertex_file, const char* fragment_file);
		void use();
		void done();

		GLuint getUniformLocation(const char* name);
		void setUniformMat4(GLuint location, glm::mat4 mvp);
	};
}
