#version 330

// Access vertex position data
layout(location=0) in vec3 position;
// Access uvs for the vertex
layout(location=1) in vec2 uvs;

uniform mat4 mvp;

out vec2 outUvs;

void main()
{
	// Set the position of the processed vertex
	gl_Position = mvp * vec4(position, 1.0);

	outUvs = uvs;
}
