#version 330 core

layout(location=0) in vec3 position;
layout(location=1) in vec2 uvs;

uniform mat4 mvp;

out vec2 outUvs;

void main()
{
	gl_Position = mvp * vec4(position, 1.0);
	outUvs = uvs;
}
