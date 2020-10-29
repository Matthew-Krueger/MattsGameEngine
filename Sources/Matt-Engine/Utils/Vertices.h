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

#ifndef MATTS_GAME_ENGINE_VERTICES_H
#define MATTS_GAME_ENGINE_VERTICES_H
/**
 * Represents a Positional Vector (of a vertex)
 */
struct MGE_PositionVector{

    /**
     * Unions a vec3 and x,y,z. Useful so it can be addressed as a 3 component vector or as x y and z components
     * like in GLSL
     */
    union{

        /**
         * The x,y,z component.
         */
        struct{

            /**
             * x,y,z components of the position
             */
            float x,y,z;
        };

        /**
         * The vector component
         */
        struct{

            /**
             * A vector representation of the position
             */
            vec3 vector;
        };
    };
};

/**
 * Represents a Positional Vector (of a vertex)
 */
struct MGE_TextureCoordVector{

    /**
     * Unions a vec3 and x,y,z. Useful so it can be addressed as a 3 component vector or as x y and z components
     * like in GLSL
     */
    union{

        /**
         * The u,v component.
         */
        struct{

            /**
             * u,v components of the position
             */
            float u,v;
        };

        /**
         * The u,v component.
         */
        struct{

            /**
             * s,t components of the position
             */
            float s,t;
        };

        /**
         * The vector component
         */
        struct{

            /**
             * A vector representation of the position
             */
            vec2 vector;
        };
    };
};

/**
 * Represents a Positional Vector (of a vertex)
 */
struct MGE_RotationVector{

    /**
     * Unions a vec3 and x,y,z. Useful so it can be addressed as a 3 component vector or as x y and z components
     * like in GLSL
     */
    union{

        /**
         * The rx,ry,rz component.
         */
        struct{

            /**
             * x,y,z components of the rotation
             */
            float rx,ry,rz;
        };

        /**
         * The vector component
         */
        struct{

            /**
             * A vector representation of the rotation
             */
            vec3 vector;
        };
    };
};

/**
 * Represents a Positional Vector (of a vertex)
 */
struct MGE_ScaleVector{

    /**
     * Unions a vec3 and x,y,z. Useful so it can be addressed as a 3 component vector or as x y and z components
     * like in GLSL
     */
    union{

        /**
         * The sx,sy,sz component.
         */
        struct{

            /**
             * sx,sy,sz components of the scale
             */
            float sx,sy,sz;
        };

        /**
         * The vector component
         */
        struct{

            /**
             * A vector representation of the scale
             */
            vec3 scale;
        };
    };
};

#endif //MATTS_GAME_ENGINE_VERTICES_H
