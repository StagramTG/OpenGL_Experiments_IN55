#version 330

layout(location=0) in vec3 position;
layout(location=1) in vec3 colors;

uniform mat4 mvp;

out vec3 outColor;

void main()
{
	gl_Position = mvp * vec4(position, 1.0);
	outColor = colors;
}
