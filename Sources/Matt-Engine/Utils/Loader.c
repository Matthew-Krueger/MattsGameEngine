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

#include "UtilsInternal.h"
#include <STB/stb_image.h>

struct MGE_RawModel* MGE_rawModelLoadToVAO(struct MGE_PositionVector* positions, GLsizeiptr positionsSize, GLuint *indices, GLsizeiptr indicesSize, struct MGE_TextureCoordVector* uvCoords) {
    struct MGE_RawModel* result = malloc(sizeof(struct MGE_RawModel));

    result->vaoID = MGE_createVAO();
    result->indices = MGE_bindIndicesBuffer(indices, indicesSize);
    result->vertices = MGE_storeDataInAttributeList(VERTEX_ATTRIB_POSITION_LOCATION, positions, sizeof(*positions), positionsSize, 3, GL_FLOAT);
    if(uvCoords != NULL)
        result->textureCoords = MGE_storeDataInAttributeList(VERTEX_ATTRIB_TEXTURE_COORD_LOCATION, uvCoords, sizeof(*uvCoords), positionsSize, 2, GL_FLOAT);
    result->length = indicesSize;

    return result;
}

void MGE_rawModelFree(struct MGE_RawModel* model) {

    glBindVertexArray(model->vaoID);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
    glDeleteVertexArrays(1, &model->vaoID);
    glDeleteBuffers(1,&model->vertices.vboID);

    free(model);

}

struct MGE_Texture* MGE_textureLoadFromFile(char * filePath){
    struct MGE_Texture* texture = malloc(sizeof( struct MGE_Texture));

    /* Init the texture */
    texture->filePath = filePath;
    unsigned char* localBuffer = NULL;
    texture->textureID = 0;
    texture->height = 0;
    texture->width = 0;
    texture->BPP = 0;

    /* Generate Texture and bind */
    glGenTextures(1, &texture->textureID);
    glBindTexture(GL_TEXTURE_2D, texture->textureID);

    /* Set up STBI and load */
    stbi_set_flip_vertically_on_load(true);
    localBuffer = stbi_load(filePath, &texture->width, &texture->height, &texture->BPP,4);

    if(localBuffer == NULL){
        char buf[256];
        sprintf(buf, "Unable to load Image File: %s", filePath);
        MGE_CORE_LOG_SEVERE(buf, stbi_failure_reason());
        return texture;
    }

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, texture->width, texture->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, localBuffer);

    glBindTexture(GL_TEXTURE_2D, 0);

    stbi_image_free(localBuffer);


    return texture;

}

void MGE_textureBind(struct MGE_Texture* texture, GLenum slot){

    glActiveTexture(slot);
    glBindTexture(GL_TEXTURE_2D, texture->textureID);

}

void MGE_textureUnbind(struct MGE_Texture* texture){

    glBindTexture(GL_TEXTURE_2D, 0);

}

void MGE_textureFree(struct MGE_Texture* texture){

    glDeleteTextures(1, &texture->textureID);

    free(texture);

}

struct MGE_TexturedModel* MGE_texturedModelCreate(struct MGE_RawModel* rawModel, struct MGE_Texture* baseColorTexture){

    struct MGE_TexturedModel* result = malloc(sizeof(struct MGE_TexturedModel));

    result->rawModel = rawModel;
    result->baseColorTexture = baseColorTexture;

    return result;

}

void MGE_texturedModelFree(struct MGE_TexturedModel* texturedModel){

    free(texturedModel);

}

GLuint MGE_createVAO() {
    GLuint result;
    glGenVertexArrays(1, &result);
    glBindVertexArray(result);
    return result;
}

struct MGE_VBO MGE_bindIndicesBuffer(GLuint *indices, GLsizeiptr size) {

    struct MGE_VBO vbo;
    glGenBuffers(1, &vbo.vboID);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, vbo.vboID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size*sizeof(GLuint), indices, GL_STATIC_DRAW);

    return vbo;

}

struct MGE_VBO MGE_storeDataInAttributeList(GLuint attributeNumber, void* data, size_t dataPtrSize, GLsizeiptr dataLength, GLint coordSize, GLenum typeOfData) {

    struct MGE_VBO vbo;
    glGenBuffers(1, &vbo.vboID);

    glBindBuffer(GL_ARRAY_BUFFER, vbo.vboID);

    char buf2[5];
    sprintf(buf2, "%ld", dataLength);

    glBufferData(GL_ARRAY_BUFFER, dataLength*dataPtrSize, data, GL_STATIC_DRAW);
    glVertexAttribPointer(attributeNumber, coordSize, typeOfData, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(attributeNumber);
    //glBindBuffer(GL_ARRAY_BUFFER, 0);

    return vbo;

}

void MGE_unbindVAO() {
    glBindVertexArray(0);
}
