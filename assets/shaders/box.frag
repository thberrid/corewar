#version 330 core

out vec3 color;

in vec3 fragmentColor;
in vec2 uv;

uniform sampler2D tex;

void main()
{
	color = fragmentColor * texture(tex, uv).rgb;
}
