//
// Created by matth on 10/24/20.
//

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
#endif //MATTS_GAME_ENGINE_VERTICES_H
