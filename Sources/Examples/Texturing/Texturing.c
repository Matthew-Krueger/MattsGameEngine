/************************************************************************************
* Matt's Game Engine is licensed under a BSD 3-Clause License                       *
*                                                                                   *
* BSD 3-Clause License                                                              *
*                                                                                   *
* Copyright (c) 2020, Matthew Krueger                                               *
* All rights reserved.                                                              *
*                                                                                   *
* Redistribution and use in source and binary forms, with or without                *
* modification, are permitted provided that the following conditions are met:       *
*                                                                                   *
* 1. Redistributions of source code must retain the above copyright notice, this    *
*    list of conditions and the following disclaimer.                               *
*                                                                                   *
* 2. Redistributions in binary form must reproduce the above copyright notice,      *
*    this list of conditions and the following disclaimer in the documentation      *
*    and/or other materials provided with the distribution.                         *
*                                                                                   *
* 3. Neither the name of the copyright holder nor the names of its                  *
*    contributors may be used to endorse or promote products derived from           *
*    this software without specific prior written permission.                       *
*                                                                                   *
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"       *
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE         *
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE    *
* DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE      *
* FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL        *
* DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR        *
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER        *
* CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,     *
* OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE     *
* OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.              *
************************************************************************************/

#include <Matts-Engine/RequiredGlobals.h>
#include <Matts-Engine/Core.h>
#include <stdlib.h>

enum Uniforms{
    TRANSFORMATION_MATRIX = 0
};

void runRenderLoop(struct MGE_Window* window, struct MGE_TexturedModel* model, struct MGE_ShaderProgram* shader);
void bindAttributes(struct MGE_ShaderProgram* program);
void getUniforms(struct MGE_ShaderProgram* program);

int main(int argc, char ** argv){

    mat4x4 matrix = {
            {1,2,3,4},
            {5,6,7,8},
            {9,10,11,12},
            {13,14,15,16}
    };
    vec3 pos = {0,0,0};
    vec3 rot = {4,0,0};
    vec3 scl = {1,1,1};
    MGE_createTransformationMatrix(matrix,pos,rot,scl);
    MGE_logInit("core.log","startupAndWindowing.log");

    MGE_APP_INFO("Starting up Example Startup and Windowing.", "");

    struct MGE_Window* window = MGE_windowInit(1920, 1080, "StartupAndWindowing");

    MGE_variableLengthArrayLargeHint(15);
    struct MGE_VariableLengthArray* vlaTextures = MGE_variableLengthArrayCreate();
    struct MGE_VariableLengthArray* vlaRawModels = MGE_variableLengthArrayCreate();
    struct MGE_TexturedModel* texturedModel = NULL;
    {
        GLuint indices[] = {
                0, 1, 3,
                3, 1, 2
        };
        struct MGE_PositionVector verticesPositions[4] = {{-.5f, .5f,   0.0f},
                                                          {-.5f, -.5f,  0.0f},
                                                          {0.5f, -0.5f, 0.0f},
                                                          {.5f,  .5f,   0.0f}};
        struct MGE_TextureCoordVector verticesTextureCoords[4] = {{0, 0},
                                                                  {0, 1},
                                                                  {1, 1},
                                                                  {1, 0}};

        struct MGE_RawModel* model = MGE_rawModelLoadToVAO(verticesPositions, 4, indices, 6, verticesTextureCoords);
        struct MGE_Texture* texture = MGE_textureLoadFromFile("Resource/Textures/Grass_BaseColor.jpg");
        texturedModel = MGE_texturedModelCreate(model, texture);
        MGE_variableLengthArrayPush(vlaTextures, texture);
        MGE_variableLengthArrayPush(vlaRawModels, model);

    }
    struct MGE_ShaderProgram* shader = MGE_shaderLoadProgramFromFiles("Resource/Shaders/TextureShader.vert.glsl", "Resource/Shaders/TextureShader.frag.glsl", bindAttributes, getUniforms);
    while(!MGE_windowShouldClose(window)){

        /* Test for input */
        if(MGE_isKeyDown(window, MGE_KEY_ESCAPE))
            MGE_windowSetShouldClose(window);

        MGE_shaderStart(shader);
        MGE_shaderLoadMat4x4f(shader, 0, matrix);
        MGE_shaderStop();

        runRenderLoop(window, texturedModel, shader);

        MGE_windowUpdate(window);

    }

    MGE_texturedModelFree(texturedModel);
    MGE_variableLengthArrayFreeRawModel(vlaRawModels);
    MGE_variableLengthArrayFreeTexture(vlaTextures);
    MGE_shaderProgramFree(shader);
    MGE_windowDelete(window);

}

void bindAttributes(struct MGE_ShaderProgram* program){

    // MGE_APP_INFO("Binding Attributes", "Binding Attributes of shader");
    MGE_shaderBindAttribute(program, 0, "position");
    MGE_shaderBindAttribute(program, 1, "textureCoords");

}

void getUniforms(struct MGE_ShaderProgram* program){

    enum Uniforms locationTransformationMatrix = TRANSFORMATION_MATRIX;
    MGE_shaderStoreUniformLocation(program, "transformationMatrix", locationTransformationMatrix);

}

void runRenderLoop(struct MGE_Window* window, struct MGE_TexturedModel* model, struct MGE_ShaderProgram* shader){

    MGE_prepareFrame();
    MGE_shaderStart(shader);
    MGE_renderTexturedModel(model);
    MGE_shaderStop();

}