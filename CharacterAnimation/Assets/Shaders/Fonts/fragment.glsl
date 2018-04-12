#version 400

// Texture0
uniform sampler2D texture;
in vec2 outUvs;

// Out color for processed fragment
out vec4 frag_color;

void main()
{
	frag_color = vec4(1.0, 1.0, 1.0, 1.0);
}

//vec4(1.0, 1.0, 1.0, texture2D(texture, outUvs).r)