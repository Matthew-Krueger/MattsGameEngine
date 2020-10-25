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

#ifndef MATTS_GAME_ENGINE_UTILSINTERNAL_H
#define MATTS_GAME_ENGINE_UTILSINTERNAL_H

#include "UtilsAPI.h"
#include "Vertices.h"

#define VERTEX_ATTRIB_POSITION_LOCATION 0
#define VERTEX_ATTRIB_TEXTURE_COORD_LOCATION 1

struct MGE_VBO{
    GLuint vboID;
};

struct MGE_RawModel{
    GLuint vaoID;
    GLsizei length;
    struct MGE_VBO vertices, indices, textureCoords;
};

struct MGE_Texture{
    GLuint textureID;
    char * filePath;
    int width;
    int height;
    int BPP;
};

struct MGE_TexturedModel{
    struct MGE_RawModel* rawModel;
    struct MGE_Texture* baseColorTexture;
};


/**
 * Creates a VBO in graphics memory and returns the id.
 * @return GLuint the VBO id.
 */
MGE_API_HIDDEN GLuint MGE_createVAO();

/**
 * Binds an indices buffer
 * @param indices The array of indices
 * @param size The size of the array
 * @return A VBO id of the index array
 */
MGE_API_HIDDEN struct MGE_VBO MGE_bindIndicesBuffer(GLuint* indices, GLsizeiptr size);

/**
 * Stores GL_FLOAT in an attribute list
 * @param attributeNumber The attribute number to store it in
 * @param data The data to write to GPU memory
 * @param dataPtrSize The size of the pointer to data (use sizeof(*data))
 * @param dataLength The size of the data to write
 * @param coordSize The number of numbers per vertex needed
 * @param typeOfData The type of data loading (in the event it is a void*, NOT YET IMPLEMENTED)
 * @return A VBO ID of the attribute list
 */
MGE_API_HIDDEN struct MGE_VBO MGE_storeDataInAttributeList(GLuint attributeNumber, void* data, size_t dataPtrSize, GLsizeiptr dataLength, GLint coordSize, GLenum typeOfData);

/**
 * Helper to unbind the current VAO
 */
MGE_API_HIDDEN void MGE_unbindVAO();

#endif //MATTS_GAME_ENGINE_UTILSINTERNAL_H
