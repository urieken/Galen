#version 330

out vec4 outColor;

uniform float u_Color;

void main()
{
	outColor = vec4(u_Color, 0.0, 0.0, 1.0);
}