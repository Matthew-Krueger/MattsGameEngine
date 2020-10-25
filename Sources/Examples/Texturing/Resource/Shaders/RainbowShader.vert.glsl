#version 400 core

in vec3 position;

out vec3 color;

void main(void){

    // Tell OpenGL the position
    gl_Position = vec4(position.xyz,1.0);

    // Define the color
    color = vec3(position.x+0.5, position.x+0.5, position.y+0.5);

}