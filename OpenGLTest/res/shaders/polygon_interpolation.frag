#version 330

in vec3 Color;

out vec4 outColor;

void main(){
    outColor = vec4(Color, 1.0);
    //outColor = vec4(0.0, 0.0, 1.0, 1.0);
}