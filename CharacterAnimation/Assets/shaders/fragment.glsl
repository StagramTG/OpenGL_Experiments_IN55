#version 330 core

in vec2 outUvs;
out vec4 frag_color;

uniform sampler2D tex;

void main()
{
    frag_color = texture(tex, outUvs);

    //frag_color = vec4(vec3(gl_FragCoord.z), 1.0);
}
