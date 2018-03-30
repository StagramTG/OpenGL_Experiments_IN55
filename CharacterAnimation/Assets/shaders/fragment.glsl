#version 330 core

// Subroutine declaration
subroutine vec4 outFragColor();

// Texture0
uniform sampler2D texture;
// Subroutine uniform
subroutine uniform outFragColor fragColor;

in vec2 outUvs;
in vec3 outColor;

// Subroutine to use with TexturedModel
subroutine(outFragColor)
vec4 outFromTexture()
{
	return texture2D(texture, outUvs);
}

// Subroutine to use with ColoredModel
subroutine(outFragColor)
vec4 outFromColor()
{
	return vec4(outColor.xyz, 1.0);
}

// Out color for processed fragment
out vec4 frag_color;

void main()
{
	// Attrib fragment color
    frag_color = fragColor();
}
