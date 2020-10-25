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

#ifndef MATTS_GAME_ENGINE_UTILSAPI_H
#define MATTS_GAME_ENGINE_UTILSAPI_H

/* Defines from GLFW, remapped to MGE */
#define 	MGE_KEY_UNKNOWN   -1
#define 	MGE_KEY_SPACE   32
#define 	MGE_KEY_APOSTROPHE   39 /* ' */
#define 	MGE_KEY_COMMA   44 /* , */
#define 	MGE_KEY_MINUS   45 /* - */
#define 	MGE_KEY_PERIOD   46 /* . */
#define 	MGE_KEY_SLASH   47 /* / */
#define 	MGE_KEY_0   48
#define 	MGE_KEY_1   49
#define 	MGE_KEY_2   50
#define 	MGE_KEY_3   51
#define 	MGE_KEY_4   52
#define 	MGE_KEY_5   53
#define 	MGE_KEY_6   54
#define 	MGE_KEY_7   55
#define 	MGE_KEY_8   56
#define 	MGE_KEY_9   57
#define 	MGE_KEY_SEMICOLON   59 /* ; */
#define 	MGE_KEY_EQUAL   61 /* = */
#define 	MGE_KEY_A   65
#define 	MGE_KEY_B   66
#define 	MGE_KEY_C   67
#define 	MGE_KEY_D   68
#define 	MGE_KEY_E   69
#define 	MGE_KEY_F   70
#define 	MGE_KEY_G   71
#define 	MGE_KEY_H   72
#define 	MGE_KEY_I   73
#define 	MGE_KEY_J   74
#define 	MGE_KEY_K   75
#define 	MGE_KEY_L   76
#define 	MGE_KEY_M   77
#define 	MGE_KEY_N   78
#define 	MGE_KEY_O   79
#define 	MGE_KEY_P   80
#define 	MGE_KEY_Q   81
#define 	MGE_KEY_R   82
#define 	MGE_KEY_S   83
#define 	MGE_KEY_T   84
#define 	MGE_KEY_U   85
#define 	MGE_KEY_V   86
#define 	MGE_KEY_W   87
#define 	MGE_KEY_X   88
#define 	MGE_KEY_Y   89
#define 	MGE_KEY_Z   90
#define 	MGE_KEY_LEFT_BRACKET   91 /* [ */
#define 	MGE_KEY_BACKSLASH   92 /* \ */
#define 	MGE_KEY_RIGHT_BRACKET   93 /* ] */
#define 	MGE_KEY_GRAVE_ACCENT   96 /* ` */
#define 	MGE_KEY_WORLD_1   161 /* non-US #1 */
#define 	MGE_KEY_WORLD_2   162 /* non-US #2 */
#define 	MGE_KEY_ESCAPE   256
#define 	MGE_KEY_ENTER   257
#define 	MGE_KEY_TAB   258
#define 	MGE_KEY_BACKSPACE   259
#define 	MGE_KEY_INSERT   260
#define 	MGE_KEY_DELETE   261
#define 	MGE_KEY_RIGHT   262
#define 	MGE_KEY_LEFT   263
#define 	MGE_KEY_DOWN   264
#define 	MGE_KEY_UP   265
#define 	MGE_KEY_PAGE_UP   266
#define 	MGE_KEY_PAGE_DOWN   267
#define 	MGE_KEY_HOME   268
#define 	MGE_KEY_END   269
#define 	MGE_KEY_CAPS_LOCK   280
#define 	MGE_KEY_SCROLL_LOCK   281
#define 	MGE_KEY_NUM_LOCK   282
#define 	MGE_KEY_PRINT_SCREEN   283
#define 	MGE_KEY_PAUSE   284
#define 	MGE_KEY_F1   290
#define 	MGE_KEY_F2   291
#define 	MGE_KEY_F3   292
#define 	MGE_KEY_F4   293
#define 	MGE_KEY_F5   294
#define 	MGE_KEY_F6   295
#define 	MGE_KEY_F7   296
#define 	MGE_KEY_F8   297
#define 	MGE_KEY_F9   298
#define 	MGE_KEY_F10   299
#define 	MGE_KEY_F11   300
#define 	MGE_KEY_F12   301
#define 	MGE_KEY_F13   302
#define 	MGE_KEY_F14   303
#define 	MGE_KEY_F15   304
#define 	MGE_KEY_F16   305
#define 	MGE_KEY_F17   306
#define 	MGE_KEY_F18   307
#define 	MGE_KEY_F19   308
#define 	MGE_KEY_F20   309
#define 	MGE_KEY_F21   310
#define 	MGE_KEY_F22   311
#define 	MGE_KEY_F23   312
#define 	MGE_KEY_F24   313
#define 	MGE_KEY_F25   314
#define 	MGE_KEY_KP_0   320
#define 	MGE_KEY_KP_1   321
#define 	MGE_KEY_KP_2   322
#define 	MGE_KEY_KP_3   323
#define 	MGE_KEY_KP_4   324
#define 	MGE_KEY_KP_5   325
#define 	MGE_KEY_KP_6   326
#define 	MGE_KEY_KP_7   327
#define 	MGE_KEY_KP_8   328
#define 	MGE_KEY_KP_9   329
#define 	MGE_KEY_KP_DECIMAL   330
#define 	MGE_KEY_KP_DIVIDE   331
#define 	MGE_KEY_KP_MULTIPLY   332
#define 	MGE_KEY_KP_SUBTRACT   333
#define 	MGE_KEY_KP_ADD   334
#define 	MGE_KEY_KP_ENTER   335
#define 	MGE_KEY_KP_EQUAL   336
#define 	MGE_KEY_LEFT_SHIFT   340
#define 	MGE_KEY_LEFT_CONTROL   341
#define 	MGE_KEY_LEFT_ALT   342
#define 	MGE_KEY_LEFT_SUPER   343
#define 	MGE_KEY_RIGHT_SHIFT   344
#define 	MGE_KEY_RIGHT_CONTROL   345
#define 	MGE_KEY_RIGHT_ALT   346
#define 	MGE_KEY_RIGHT_SUPER   347
#define 	MGE_KEY_MENU   348
#define 	MGE_KEY_LAST   GLFW_KEY_MENU

#include "../EngineForwardDecls.h"
#include "Vertices.h"

/**
 * \brief Asks the kernel if the specified key id is down
 * @param window The window context to ask about
 * @param keyNumber The Key Number. Use GLFW_KEY_WHATEVER
 * @return if the key is down
 */
MGE_API bool MGE_isKeyDown(struct MGE_Window* window, int keyNumber);

/**Vertices
 * \brief Load positions to the GPU
 * @param \link MGE_PositionVector MGE_PositionVector \endlink positions The array of positions vectors.
 * @param GLsizeiptr positionsSize The size of the positions (number of vertices, not number of floats).
 * @param indices GLuint the array of indices that represent the model.
 * @param indicesSize GLsizeiptr the size of the indices array.
 * @param uvCoords The \link MGE_TextureCoordVector MGE_TextureCoordVector \endlink corresponding to each position
 * @return \link MGE_RawModel MGE_RawModel \endlink A constructed RawModel
 */
MGE_API struct MGE_RawModel* MGE_rawModelLoadToVAO(struct MGE_PositionVector* positions, GLsizeiptr positionsSize, GLuint *indices, GLsizeiptr indicesSize, struct MGE_TextureCoordVector* uvCoords);

/**
 * \brief Unload from the Graphics Memory the Raw Model
 * \note texture will point to deallocated memory after this call. Set equal to NULL
 * \note to avoid problems.
 * @param model
 */
MGE_API void MGE_rawModelFree(struct MGE_RawModel* model);

/**
 * \brief Load an image from a file to the GPU
 * \note filePath becomes part of the Texture Struct. Please do not free it, and instead
 * \note let it be handled by \link MGE_textureFree MGE_textureFree \endlink instead.
 * \note I recommend setting your original pointer to NULL
 * @param filePath The path to the image to load
 * @return A constructed \link MGE_Texture MGE_Texture \endlink object
 */
MGE_API struct MGE_Texture* MGE_textureLoadFromFile(char * filePath);

/**
 * \brief Binds a texture to a slot
 * @param texture The texture to bind
 * @param slot The slot to bind it to
 */
MGE_API void MGE_textureBind(struct MGE_Texture* texture, GLenum slot);

/**
 * \brief Unbinds a texture
 * @param texture The texture to unbind
 */
MGE_API void MGE_textureUnbind(struct MGE_Texture* texture);

/**
 * \brief Frees a texture from video memory and local memory
 * \note texture will point to deallocated memory after this call. Set equal to NULL
 * \note to avoid problems
 * @param texture The texture to free
 */
MGE_API void MGE_textureFree(struct MGE_Texture* texture);

/**
 * \brief Create a new textured model
 * \note RawModel and Texture are shared and are NOT freed automatically
 * @param rawModel The RawModel to bind
 * @param baseColorTexture The Base color texture to bind
 * @return
 */
MGE_API struct MGE_TexturedModel* MGE_texturedModelCreate(struct MGE_RawModel* rawModel, struct MGE_Texture* baseColorTexture);

/**
 * Frees a textured model from memory
 * \note DOES NOT FREE RAWMODEL OR TEXTURE MEMORY. FREE SEPARATELY
 * @param texturedModel The textured model to free
 */
MGE_API void MGE_texturedModelFree(struct MGE_TexturedModel* texturedModel);

/**
 * \brief Sets a window resize callback.
 * @param window The window to set the callback on
 * @param windowResizeCallback The Callback to set
 */
MGE_API void MGE_windowSetSizeCallback(struct MGE_Window* window, void (*windowResizeCallback)(GLFWwindow*window, int width, int height));

/**
 * \brief Set an error callback for OpenGL
 * @param errorCallback The Error Callback to set
 */
MGE_API void MGE_windowSetDebugCallback(void (*errorCallback)(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *message, const void *userParam));


/**
 * \brief The Callback for a window size change
 * @param window OpenGL Provided Value
 * @param width OpenGL Provided Value
 * @param height OpenGL Provided Value
 */
MGE_API void MGE_windowDefaultSizeCallback(GLFWwindow* window, int width, int height);

/**
 * \brief Provides a callback for OpenGL errors, and uses severe error log
 * @param source OpenGL Provided Value
 * @param type OpenGL Provided Value
 * @param id OpenGL Provided Value
 * @param severity OpenGL Provided Value
 * @param length OpenGL Provided Value
 * @param message OpenGL Provided Value
 * @param userParam OpenGL Provided Value
 */
MGE_API void MGE_windowDefaultDebugCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *message, const void *userParam);


#endif //MATTS_GAME_ENGINE_UTILSAPI_H
