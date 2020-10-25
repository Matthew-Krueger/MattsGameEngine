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

#ifndef MATTS_GAME_ENGINE_GRAPHICSINTERNAL_H
#define MATTS_GAME_ENGINE_GRAPHICSINTERNAL_H

#include "GraphicsAPI.h"

/**
 * A representation of the window (wrapped for ease)
 */
struct MGE_Window{

    GLFWwindow* window;

};

struct MGE_ShaderSource{
    char * shaderSource;
    size_t length;
};

struct MGE_ShaderProgram{

    GLuint vertexShaderID;
    GLuint fragmentShaderID;
    GLuint programID;
    struct MGE_ShaderSource vertexShaderSource;
    struct MGE_ShaderSource fragmentShaderSource;


} ;

/**
 * Loads a shader source to memory
 * @param filePath The path to the file to read.
 * @return The shader source string
 */
MGE_API_HIDDEN void MGE_shaderRead(const char * filePath, char** dataptr, size_t* sizeptr);

/**
 * Loads a shader to the GPU memory from source
 * @param source The source code of the shader
 * @param type The type of shader to load
 * @return The Shader ID from OpenGL.
 */
MGE_API_HIDDEN GLuint MGE_shaderLoad(const char * source, GLenum type);

#endif //MATTS_GAME_ENGINE_GRAPHICSINTERNAL_H
