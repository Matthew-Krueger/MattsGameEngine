#version 400 core

in vec2 passTextureCoords;

out vec4 finalColor;

uniform sampler2D baseColorSampler;

void main(void){

    finalColor = texture(baseColorSampler, passTextureCoords);

}