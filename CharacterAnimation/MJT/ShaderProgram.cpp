#include "ShaderProgram.h"

namespace mjt
{
	ShaderProgram::ShaderProgram()
	{
	}

	ShaderProgram::~ShaderProgram()
	{
		glDeleteProgram(m_id);
	}

	bool ShaderProgram::init(const char * vertex_file, const char * fragment_file)
	{
		/*Create program*/
		m_id = glCreateProgram();

		/*Create vertex and fragment shader*/
		GLuint vertex_shader = glCreateShader(GL_VERTEX_SHADER);
		GLuint fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);

		/*Set sources for vertex shader*/
		std::ifstream shader_stream;
		std::string tmp;

		/*Extract vertex shader content*/
		shader_stream.open(vertex_file);
		if (!shader_stream)
		{
			std::cerr << "Vertex file not found" << std::endl;
			return false;
		}

		std::string vertex_content = "";
		while (std::getline(shader_stream, tmp))
		{
			vertex_content.append(tmp.append("\n"));
		}

		shader_stream.close();

		/*Extract fragment sader content*/
		shader_stream.open(fragment_file);
		if (!shader_stream)
		{
			std::cerr << "Fragment file not found" << std::endl;
			return false;
		}

		std::string fragment_content = "";
		while (std::getline(shader_stream, tmp))
		{
			fragment_content.append(tmp.append("\n"));
		}

		shader_stream.close();

		/*Set source to shader*/
		const char* vertex_sources = vertex_content.c_str();
		glShaderSource(vertex_shader, 1, &vertex_sources, nullptr);

		const char* fragment_sources = fragment_content.c_str();
		glShaderSource(fragment_shader, 1, &fragment_sources, nullptr);

		/*Compile shaders*/
		glCompileShader(vertex_shader);
		glCompileShader(fragment_shader);

		/*Check if errors append while compiling*/
		GLint success;
		glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			GLchar infoLog[1024];
			glGetShaderInfoLog(vertex_shader, sizeof(infoLog), NULL, infoLog);
			fprintf(stderr, "Error compiling shader type %d: '%s'\n", GL_VERTEX_SHADER, infoLog);
		}

		glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			GLchar infoLog[1024];
			glGetShaderInfoLog(fragment_shader, sizeof(infoLog), NULL, infoLog);
			fprintf(stderr, "Error compiling shader type %d: '%s'\n", GL_FRAGMENT_SHADER, infoLog);
		}

		/*link shaders to program*/
		glAttachShader(m_id, vertex_shader);
		glAttachShader(m_id, fragment_shader);

		glLinkProgram(m_id);

		/*Check if there is errors in program*/
		glGetProgramiv(m_id, GL_LINK_STATUS, &success);
		if (!success)
		{
			GLchar infoLog[1024];
			glGetProgramInfoLog(m_id, sizeof(infoLog), NULL, infoLog);
			fprintf(stderr, "Error in program: '%s'\n", infoLog);
		}

		/*Delete intermediate shader*/
		glDetachShader(m_id, vertex_shader);
		glDetachShader(m_id, fragment_shader);

		glDeleteShader(vertex_shader);
		glDeleteShader(fragment_shader);

		return true;
	}

	void ShaderProgram::use()
	{
		glUseProgram(m_id);
	}

	void ShaderProgram::done()
	{
		glUseProgram(0);
	}

	GLuint ShaderProgram::getUniformLocation(const char* name)
	{
		GLuint location = glGetUniformLocation(m_id, name);
		return location;
	}

	void ShaderProgram::setUniformMat4(GLuint location, glm::mat4 mvp)
	{
		glUniformMatrix4fv(location, 1, GL_FALSE, &mvp[0][0]);
	}

	GLuint ShaderProgram::getSubroutineLocation(GLenum shaderType, const char * name)
	{
		GLuint location = glGetSubroutineIndex(m_id, shaderType, name);
		return location;
	}

	void ShaderProgram::setUniformSubroutine(GLenum shaderType, GLuint index)
	{
		glUniformSubroutinesuiv(shaderType, 1, &index);
	}

	void ShaderProgram::setUniformInt(GLuint location, GLuint value)
	{
		glUniform1i(location, value);
	}

	void ShaderProgram::setUniformFloat(GLuint location, GLfloat value)
	{
		glUniform1f(location, value);
	}

	void ShaderProgram::setUniformVec3Float(GLuint location, glm::vec3 value)
	{
		glUniform3f(location, value.x, value.y, value.z);
	}
}
