#version 330

out vec4 outColor;

uniform vec4 u_Color;

void main(){
    outColor = vec4(u_Color);
}