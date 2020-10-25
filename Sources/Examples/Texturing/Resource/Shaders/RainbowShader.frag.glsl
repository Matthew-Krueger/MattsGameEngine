#version 400 core

in vec3 color;

out vec4 finalColor;

void main(void){

    finalColor = vec4(color.xyz,1.0);

}