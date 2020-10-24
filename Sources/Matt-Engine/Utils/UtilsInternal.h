//
// Created by matth on 10/24/20.
//

#ifndef MATTS_GAME_ENGINE_UTILSINTERNAL_H
#define MATTS_GAME_ENGINE_UTILSINTERNAL_H

#include "UtilsAPI.h"
#include "Vertices.h"

#define VERTEX_ATTRIB_POSITION_LOCATION 0

struct MGE_VBO{
    GLuint vboID;
};

struct MGE_RawModel{
    GLuint vaoID;
    GLsizei length;
    struct MGE_VBO vertices, indices;
};


/**
 * Creates a VBO in graphics memory and returns the id.
 * @return GLuint the VBO id.
 */
MGE_API_HIDDEN GLuint MGE_createVAO();

/**
 * Binds an indices buffer
 * @param indices The array of indices
 * @param ize The size of the array
 * @return A VBO id of the index array
 */
MGE_API_HIDDEN struct MGE_VBO MGE_bindIndicesBuffer(GLuint* indices, GLsizeiptr size);

/**
 * Stores GL_FLOAT in an attribute list
 * @param attributeNumber The attribute number to store it in
 * @param data The data to write to GPU memory
 * @param size The size of the data to write
 * @return A VBO ID of the attribute list
 */
MGE_API_HIDDEN struct MGE_VBO MGE_storeDataInAttributeList(GLuint attributeNumber, struct MGE_PositionVector* data, GLsizeiptr size, GLenum typeOfData);

/**
 * Helper to unbind the current VAO
 */
MGE_API_HIDDEN void MGE_unbindVAO();

#endif //MATTS_GAME_ENGINE_UTILSINTERNAL_H
