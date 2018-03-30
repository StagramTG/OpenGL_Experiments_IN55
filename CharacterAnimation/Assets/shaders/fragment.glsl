#version 330 core

subroutine vec4 outFragColor();

uniform sampler2D tex;
subroutine uniform outFragColor fragColor;

in vec2 outUvs;
in vec3 outColor;

out vec4 frag_color;

subroutine(outFragColor)
vec4 outFromTexture()
{
	return texture(tex, outUvs);
}

subroutine(outFragColor)
vec4 outFromColor()
{
	return vec4(outColor.xyz, 1.0);
	//return vec4(1, 0, 0, 1.0);
}

void main()
{
    frag_color = fragColor();
}
