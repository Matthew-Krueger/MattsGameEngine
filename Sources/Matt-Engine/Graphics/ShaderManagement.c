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

#include "GraphicsInternal.h"

#include <stdio.h>
#include <stdlib.h>

#ifndef  READALL_CHUNK
#define  READALL_CHUNK  262144
#endif

struct MGE_ShaderProgram* MGE_shaderLoadProgramFromFiles(const char *vertexShaderPath, const char *fragmentShaderPath, void (*bindAttributes)(struct MGE_ShaderProgram*), void (*getAllUniformLocations)(struct MGE_ShaderProgram*)) {

    struct MGE_ShaderProgram* result = malloc(sizeof(struct MGE_ShaderProgram));

    MGE_shaderRead(vertexShaderPath, &result->vertexShaderSource.shaderSource, &result->vertexShaderSource.length);
    MGE_shaderRead(fragmentShaderPath, &result->fragmentShaderSource.shaderSource, &result->fragmentShaderSource.length);

    MGE_shaderCompileFromTargetProgram(result, bindAttributes);
    result->uniforms=malloc(sizeof(GLint));
    result->uniformsSize=1;

    getAllUniformLocations(result);

    return result;

}


struct MGE_ShaderProgram* MGE_shaderCompileFromTargetProgram(struct MGE_ShaderProgram* target, void (*bindAttributes)(struct MGE_ShaderProgram*)) {

    target->vertexShaderID = MGE_shaderLoad(target->vertexShaderSource.shaderSource, GL_VERTEX_SHADER);
    target->fragmentShaderID = MGE_shaderLoad(target->fragmentShaderSource.shaderSource, GL_FRAGMENT_SHADER);

    target->programID = glCreateProgram();

    glAttachShader(target->programID, target->vertexShaderID);
    glAttachShader(target->programID, target->fragmentShaderID);
    bindAttributes(target);
    glLinkProgram(target->programID);

    GLint programLinked;
    glGetProgramiv(target->programID, GL_LINK_STATUS, &programLinked);
    if (programLinked != GL_TRUE)
    {
        GLsizei log_length = 0;
        GLchar message[1024];
        glGetProgramInfoLog(target->programID, 1024, &log_length, message);
        // Write the error to a log
        MGE_CORE_LOG_CRITICAL("Unable to link shader program", message, 6);
    }

    glValidateProgram(target->programID);

    GLint programValidated;
    glGetProgramiv(target->programID, GL_VALIDATE_STATUS, &programValidated);
    if(programValidated != GL_TRUE){
        GLsizei log_length = 0;
        GLchar message[1024];
        glGetProgramInfoLog(target->programID, 1024, &log_length, message);
        // Write the error to a log
        MGE_CORE_LOG_CRITICAL("Shader validation failed", message, 6);
    }

    return target;

}

void MGE_shaderStoreUniformLocation(struct MGE_ShaderProgram* target, const char * uniformName, size_t index){

    if(target->uniformsSize < index){
        /* reallocate uniforms */
        target->uniformsSize += (index-target->uniformsSize) + 1;
        target->uniforms = realloc(target->uniforms, target->uniformsSize);
    }

    target->uniforms[index] = glGetUniformLocation(target->programID, uniformName);

}


void MGE_shaderLoadFloat(struct MGE_ShaderProgram* target, size_t index, GLfloat value){

    glUniform1f(target->uniforms[index], value);

}

void MGE_shaderLoadVec3(struct MGE_ShaderProgram* target, size_t index, vec3 vector){

    glUniform3fv(target->uniforms[index], 3, vector);

}

void MGE_shaderLoadBol(struct MGE_ShaderProgram* target, size_t index,  bool value){

    glUniform1i(target->uniforms[index], value);

}

void MGE_shaderLoadMat4x4f(struct MGE_ShaderProgram* target, size_t index, mat4x4 matrixToLoad){

    GLfloat toLoad[16];
    for(int i=0; i<16; ++i){
        toLoad[i] = matrixToLoad[i/4][i%4];
    }
    glUniformMatrix4fv(target->uniforms[index], 1, GL_TRUE, (GLfloat*)toLoad);

}

void MGE_createTransformationMatrix(mat4x4 matrix, vec3 transformation, vec3 rotation, vec3 scale){
    mat4x4_identity(matrix);
    mat4x4_translate(matrix, transformation[0], transformation[1], transformation[2]);
    mat4x4_rotate_X(matrix,matrix,rotation[0]);
    mat4x4_rotate_Y(matrix,matrix,rotation[1]);
    mat4x4_rotate_Z(matrix,matrix,rotation[2]);
    mat4x4_scale_aniso(matrix,matrix,scale[0],scale[1],scale[2]);
}

void MGE_shaderProgramFree(struct MGE_ShaderProgram* shaderProgram) {

    MGE_shaderStop();

    glDetachShader(shaderProgram->programID, shaderProgram->vertexShaderID);
    glDetachShader(shaderProgram->programID, shaderProgram->fragmentShaderID);

    free(shaderProgram->vertexShaderSource.shaderSource);
    free(shaderProgram->fragmentShaderSource.shaderSource);
    glDeleteProgram(shaderProgram->programID);

    free(shaderProgram->uniforms);

    free(shaderProgram);

}


void MGE_shaderRead(const char* filePath, char** dataptr, size_t* sizeptr) {

    /* Create file and get size */
    char  *data = NULL, *temp;
    size_t size = 0;
    size_t used = 0;
    size_t n;
    int status = 0;
    FILE* in = fopen(filePath, "rb");

    /* None of the parameters can be NULL. */
    if (in == NULL || dataptr == NULL || sizeptr == NULL) {
        MGE_CORE_LOG_CRITICAL("Unable to open shader file", filePath, 5);
    }

    /* A read error already occurred? */
    if (ferror(in)) {
        MGE_CORE_LOG_CRITICAL("Unable to read shader file", filePath, 5);
    }

    while (1) {

        if (used + READALL_CHUNK + 1 > size) {
            size = used + READALL_CHUNK + 1;

            /* Overflow check. Some ANSI C compilers
               may optimize this away, though. */
            if (size <= used) {
                free(data);
                MGE_CORE_LOG_CRITICAL("Too much shader input", filePath,5);
            }

            temp = realloc(data, size);
            if (temp == NULL) {
                free(data);
                MGE_CORE_LOG_CRITICAL("No memory to read file", filePath,5);
            }
            data = temp;
        }

        n = fread(data + used, 1, READALL_CHUNK, in);
        if (n == 0)
            break;

        used += n;
    }

    if (ferror(in)) {
        free(data);
        MGE_CORE_LOG_CRITICAL("Input Stream error while reading shader", filePath,5);
    }

    temp = realloc(data, used + 1);
    if (temp == NULL) {
        free(data);
        MGE_CORE_LOG_CRITICAL("No memory to read file", filePath,5);
    }
    data = temp;
    data[used] = '\0';

    *dataptr = data;
    *sizeptr = used;

}

GLuint MGE_shaderLoad(const char* source, GLenum type) {
    GLuint shaderID = glCreateShader(type);

    glShaderSource(shaderID, 1, &source, NULL);
    glCompileShader(shaderID);

    GLint vertex_compiled;
    glGetShaderiv(shaderID, GL_COMPILE_STATUS, &vertex_compiled);
    if (vertex_compiled != GL_TRUE)
    {
        GLsizei log_length = 0;
        GLchar message[1024];
        glGetShaderInfoLog(shaderID, 1024, &log_length, message);
        // Write the error to a log
        MGE_CORE_LOG_SEVERE("Error Compiling Shader. Source:",source);
        MGE_CORE_LOG_CRITICAL("Error compiling Shader from source", message, 6);
    }

    return shaderID;

}

void MGE_shaderStart(struct MGE_ShaderProgram *shaderProgram) {
    glUseProgram(shaderProgram->programID);
}

void MGE_shaderStop() {
    glUseProgram(0);
}

void MGE_shaderBindAttribute(struct MGE_ShaderProgram *shaderProgram, GLuint attribute, const char *variableName) {
    glBindAttribLocation(shaderProgram->programID, attribute, variableName);
}
