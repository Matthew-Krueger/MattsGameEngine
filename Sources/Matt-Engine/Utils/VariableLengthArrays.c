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

static size_t MGE_VLA_LARGE_HINT = 0;

void MGE_variableLengthArrayLargeHint(size_t sizeHint){

    MGE_VLA_LARGE_HINT = sizeHint;

}

struct MGE_VariableLengthArray* MGE_variableLengthArrayCreate(){

    struct MGE_VariableLengthArray* result = malloc(sizeof(struct MGE_VariableLengthArray));

    result->length = 0;

    if(MGE_VLA_LARGE_HINT >= MGE_VLA_LARGE_THRESHOLD){
        result->bufLen = MGE_VLA_LARGE_HINT;
        result->buffer = malloc(sizeof(void**)* MGE_VLA_LARGE_HINT);
    }else{
        result->bufLen = 1;
        result->buffer = malloc(sizeof(void **) * 1);
    }

    MGE_VLA_LARGE_HINT = 0;

    return result;

}

void MGE_variableLengthArrayPush(struct MGE_VariableLengthArray* array, void* value){

    size_t newSize = array->length;
    ++newSize;

    if(newSize>array->bufLen){
        size_t newBufLen = array->bufLen * MGE_VLA_GROTH_FACTOR + 1;
        array->buffer = realloc(array->buffer, newBufLen*sizeof(void*));
        array->bufLen = newBufLen;
    }

    array->buffer[array->length] = value;
    array->length=newSize;

}

void* MGE_variableLengthArrayPop(struct MGE_VariableLengthArray* array){

    if(array->length == 0){
        return NULL;
    }

    void* result = array->buffer[array->length-1];
    --array->length;

    return result;

}

void* MGE_variableLengthArrayPeek(struct MGE_VariableLengthArray* array){

    return array->buffer[array->length-1];

}

void MGE_variableLengthArrayFree(struct MGE_VariableLengthArray* array){

    free(array->buffer);
    free(array);

}

void MGE_variableLengthArrayFreeRawModel(struct MGE_VariableLengthArray* array){
    struct MGE_RawModel* rawModel;
    rawModel = MGE_variableLengthArrayPop(array);
    while(rawModel != NULL){
        MGE_rawModelFree(rawModel);
        rawModel = MGE_variableLengthArrayPop(array);
    }

    MGE_variableLengthArrayFree(array);

}


void MGE_variableLengthArrayFreeTexture(struct MGE_VariableLengthArray* array){

    struct MGE_Texture* texture;
    texture = MGE_variableLengthArrayPop(array);
    while(texture != NULL){
        MGE_textureFree(texture);
        texture = MGE_variableLengthArrayPop(array);
    }

    MGE_variableLengthArrayFree(array);

}
