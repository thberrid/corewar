#version 330 core

layout(location = 0) in vec3 pos;
layout(location = 1) in vec3 col;
layout(location = 2) in vec2 texUV;

uniform mat4 modelViewMatrix;

out vec3 fragmentColor;
out vec2 uv;

void main()
{
	gl_Position = modelViewMatrix * vec4(pos, 1);

	fragmentColor = col;
	uv = texUV;
}
