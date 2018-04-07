#version 400

// Access vertex position data
layout(location=0) in vec3 position;
// Access uvs for the vertex
layout(location=1) in vec2 uvs;
// Access color for the vertex
layout(location=2) in vec3 color;

// Define subroutine type
subroutine void passOutData();

// Subroutine to call
subroutine uniform passOutData outData;
uniform mat4 mvp;

// Pass uvs to fragment shader
out vec2 outUvs;
// Pass color to fragment shader
out vec3 outColor;

// Subroutine to use with TexturedModel
subroutine(passOutData)
void passOutUvs()
{
	outUvs = uvs;
}

// Subroutine to use with ColoredModel
subroutine(passOutData)
void passOutColor()
{
	outColor = color;
}

void main()
{
	// Set the position of the processed vertex
	gl_Position = mvp * vec4(position, 1.0);
	// Fill output data to fragment shader with appropriate subroutine
	outData();
}
