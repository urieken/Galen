#version 330

in vec3 Color;

out vec4 outColor;

void main(){
    //outColor = vec4(1.0 - Color.x, 1.0 - Color.y, 1.0 - Color.z, 1.0);
    outColor = vec4(1.0 - Color, 1.0);
}