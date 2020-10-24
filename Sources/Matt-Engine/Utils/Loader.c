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

#include "UtilsAPI.h"
#include "UtilsInternal.h"

struct MGE_RawModel* MGE_loadToVAO(struct MGE_PositionVector* positions, GLsizeiptr positionsSize, GLuint *indices, GLsizeiptr indicesSize) {
    struct MGE_RawModel* result = malloc(sizeof(struct MGE_RawModel));

    result->vaoID = MGE_createVAO();
    result->indices = MGE_bindIndicesBuffer(indices, indicesSize);
    result->vertices = MGE_storeDataInAttributeList(VERTEX_ATTRIB_POSITION_LOCATION, positions, positionsSize, GL_FLOAT);
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

struct MGE_VBO MGE_storeDataInAttributeList(GLuint attributeNumber, struct MGE_PositionVector* data, GLsizeiptr size, GLenum typeOfData) {

    struct MGE_VBO vbo;
    glGenBuffers(1, &vbo.vboID);

    glBindBuffer(GL_ARRAY_BUFFER, vbo.vboID);

    char buf2[5];
    sprintf(buf2, "%ld", size);

    void* rawData = (void*) data;

    glBufferData(GL_ARRAY_BUFFER, size*sizeof(struct MGE_PositionVector), rawData, GL_STATIC_DRAW);
    glVertexAttribPointer(attributeNumber, 3, typeOfData, GL_FALSE, 0, 0);
    glEnableVertexAttribArray(attributeNumber);
    //glBindBuffer(GL_ARRAY_BUFFER, 0);

    return vbo;

}

void MGE_unbindVAO() {
    glBindVertexArray(0);
}

