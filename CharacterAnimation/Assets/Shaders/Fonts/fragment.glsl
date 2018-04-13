#version 330

// Texture0
uniform sampler2D texture;
in vec2 outUvs;

void main()
{
	gl_FragColor = vec4(1.0, 1.0, 1.0, texture2D(texture, outUvs).r);
}

//vec4(1.0, 1.0, 1.0, texture2D(texture, outUvs).r)