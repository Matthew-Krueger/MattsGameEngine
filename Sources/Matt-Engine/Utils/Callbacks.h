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

#ifndef MATTS_GAME_ENGINE_CALLBACKS_H
#define MATTS_GAME_ENGINE_CALLBACKS_H

#include "../Graphics/Displays.h"

MGE_API void MGE_setWindowResizeCallback(MGE_Window *window, void (*windowResizeCallback)(GLFWwindow*window, int width, int height));
MGE_API void MGE_setDebugMessageCallback(void (*errorCallback)(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *message, const void *userParam));


/**
 * The Callback for a window size change
 * @param window OpenGL Provided Value
 * @param width OpenGL Provided Value
 * @param height OpenGL Provided Value
 */
void MGE_framebufferSizeCallback(GLFWwindow* window, int width, int height);

/**
 * Provides a callback for OpenGL errors, and uses severe error log
 * @param source OpenGL Provided Value
 * @param type OpenGL Provided Value
 * @param id OpenGL Provided Value
 * @param severity OpenGL Provided Value
 * @param length OpenGL Provided Value
 * @param message OpenGL Provided Value
 * @param userParam OpenGL Provided Value
 */
MGE_API void MGE_debugMessageCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar *message, const void *userParam);

#endif //MATTS_GAME_ENGINE_CALLBACKS_H
