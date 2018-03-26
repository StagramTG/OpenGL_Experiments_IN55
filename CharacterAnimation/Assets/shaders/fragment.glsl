#version 330 core

in vec2 outUvs;
out vec4 frag_color;

uniform sampler2D tex;

void main()
{
	vec4 color = vec4(0.5f, 0.5f, 0.5f, 1);
    frag_color = mix(texture(tex, outUvs), color, 0.2f);
}
