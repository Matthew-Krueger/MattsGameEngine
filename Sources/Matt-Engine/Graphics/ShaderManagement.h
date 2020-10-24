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

#ifndef MATTS_GAME_ENGINE_SHADERMANAGEMENT_H
#define MATTS_GAME_ENGINE_SHADERMANAGEMENT_H

typedef struct {
    char * shaderSource;
    size_t length;
} MGE_ShaderSource;

typedef struct{

    GLuint vertexShaderID;
    GLuint fragmentShaderID;
    GLuint programID;
    MGE_ShaderSource vertexShaderSource;
    MGE_ShaderSource fragmentShaderSource;


} MGE_ShaderProgram;

/**
 *
 * Loads a shader into GPU memory from the disk.
 * @param vertexShaderPath The path to the Vertex Shader source
 * @param fragmentShaderPath The path to the Fragment Shader source
 * @return The Shader Program
 * @param bindAttributes The lambda to bind attributes in the program
 * @return
 */
MGE_API MGE_ShaderProgram* MGE_shaderLoadProgramFromFiles(const char* vertexShaderPath, const char* fragmentShaderPath, void (*bindAttributes)(MGE_ShaderProgram*));

/**
 * Loads a shader into GPU memory from CPU memory
 * @param vertexSource The Vertex Shader source to attach
 * @param fragmentSource The Fragment Shader source to attach
 * @return The shader program
 */
MGE_API MGE_ShaderProgram* MGE_shaderCompileFromTargetProgram(MGE_ShaderProgram* target);

/**
 * Tell OpenGL to use a Shader Program
 * @param shaderProgram The Shader Program to use
 */
MGE_API void MGE_shaderStart(MGE_ShaderProgram* shaderProgram);

/**
 * Tell OpenGL to no longer use a shader
 */
MGE_API void MGE_shaderStop();


/**
 * Frees a shader program and deletes everything from memory
 * @param shaderProgram The shader program to delete
 */
MGE_API void MGE_freeShaderProgram(MGE_ShaderProgram* shaderProgram);

/**
 * Binds an attribute to a part of the shader
 * @param shaderProgram The shader program to bind to.
 * @param attribute The attribute number to bind.
 * @param variableName The variable name to bind the attribute to.
 */
MGE_API void MGE_shaderBindAttribute(MGE_ShaderProgram* shaderProgram, GLuint attribute, const char* variableName);

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

#endif //MATTS_GAME_ENGINE_SHADERMANAGEMENT_H
