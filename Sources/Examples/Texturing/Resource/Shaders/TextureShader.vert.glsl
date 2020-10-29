#version 400 core

in vec3 position;
in vec2 textureCoords;

out vec2 passTextureCoords;

uniform mat4 transformationMatrix;

void main(void){

    // Tell OpenGL the position
    gl_Position = vec4(position.xyz,1.0)*transformationMatrix;

    // Define the color
    passTextureCoords = textureCoords;

}