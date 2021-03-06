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

void runRenderLoop(struct MGE_Window* window, struct MGE_RawModel* rawModel, struct MGE_ShaderProgram* shader);
void bindAttributes(struct MGE_ShaderProgram* program);
void getUniforms(struct MGE_ShaderProgram* program);


int main(int argc, char ** argv){

    MGE_logInit("core.log","startupAndWindowing.log");

    MGE_APP_INFO("Starting up Example Startup and Windowing.", "");

    struct MGE_Window* window = MGE_windowInit(1920, 1080, "StartupAndWindowing");

    GLuint indices[] = {
            0,1,3,
            3,1,2
    };

    struct MGE_PositionVector vertex1, vertex2, vertex3, vertex4;
    vertex1.vector[0] = -0.5f;
    vertex1.vector[1] = 0.5f;
    vertex1.vector[2] = 0.0f;
    vertex2.vector[0] = -0.5f;
    vertex2.vector[1] = -0.5f;
    vertex2.vector[2] = 0.0f;
    vertex3.vector[0] = 0.5f;
    vertex3.vector[1] = -0.5f;
    vertex3.vector[2] = 0.0f;
    vertex4.vector[0] = .5f;
    vertex4.vector[1] = .5f;
    vertex4.vector[2] = 0.0f;
    struct MGE_PositionVector vertices[4] = {vertex1, vertex2, vertex3, vertex4};

    struct MGE_RawModel* model = MGE_rawModelLoadToVAO(vertices, 4, indices, 6, NULL);
    struct MGE_ShaderProgram* shader = MGE_shaderLoadProgramFromFiles("Shaders/RainbowShader.vert.glsl", "Shaders/RainbowShader.frag.glsl", bindAttributes, getUniforms);

    while(!MGE_windowShouldClose(window)){

        /* Test for input */
        if(MGE_isKeyDown(window, MGE_KEY_ESCAPE))
            MGE_windowSetShouldClose(window);

        runRenderLoop(window, model, shader);

        MGE_windowUpdate(window);

    }

    MGE_rawModelFree(model);
    MGE_shaderProgramFree(shader);
    MGE_windowDelete(window);

}

void bindAttributes(struct MGE_ShaderProgram* program){

    MGE_APP_INFO("Binding Attributes", "Binding Attributes of shader");
    MGE_shaderBindAttribute(program, 0, "position");

}

void getUniforms(struct MGE_ShaderProgram* program){

}

void runRenderLoop(struct MGE_Window* window, struct MGE_RawModel* model, struct MGE_ShaderProgram* shader){

    MGE_prepareFrame();
    MGE_shaderStart(shader);
    MGE_renderRawModel(model);
    MGE_shaderStop();

}