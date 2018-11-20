#version 330 core

layout (location = 0) out vec4 color;

uniform vec4 u_Color;
uniform sampler2D u_Texture;

in vec2 v_TexCoord;

void main(){
	//color = vec4(0.0, 1.0, 0.0, 1.0);
	vec4 texColor = texture(u_Texture, v_TexCoord);
	//color = u_Color;
	color = texColor * u_Color;
}