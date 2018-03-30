#version 330 core

layout(location=0) in vec3 position;
layout(location=1) in vec2 uvs;
layout(location=2) in vec3 color;

/* Define subroutine type */
subroutine void passOutData();

/* Subroutine to call */
subroutine uniform passOutData outData;
uniform mat4 mvp;

out vec2 outUvs;
out vec3 outColor;

subroutine(passOutData)
void passOutUvs()
{
	outUvs = uvs;
}

subroutine(passOutData)
void passOutColor()
{
	outColor = color;
}

void main()
{
	gl_Position = mvp * vec4(position, 1.0);
	outData();
}
