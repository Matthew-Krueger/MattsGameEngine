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

#ifndef MATTS_GAME_ENGINE_DISPLAYS_H
#define MATTS_GAME_ENGINE_DISPLAYS_H

#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <stdbool.h>

/**
 * A representation of the window (wrapped for ease)
 */
typedef struct{

    /**
     * The actual window context from GLFW
     */
    GLFWwindow* window;

} MGE_Window;

/**
 * Initialize a GL Context with a width, height, and windowName
 * @param width The Width of the new window to create.
 * @param height The height of the new window to create.
 * @param windowName The name of the window to create
 * @return {\link MGE_Window MGE_Window* \endlink}, a representation of the GLFWwindow
 */
MGE_API MGE_Window* MGE_initWindow(int width, int height, const char* windowName);

/**
 * Delete the memory and GL context associated with a window
 * @param window
 */
MGE_API void MGE_deleteWindow(MGE_Window* window);

/**
 * Tests if a window should close
 * @param window The window to check
 * @return bool on whether the window should close
 */
MGE_API bool MGE_windowShouldClose(MGE_Window* window);

/**
 * Poll OpenGL for updates and swap the front and back buffers
 * @param window The MGE_Window to do this to
 */
MGE_API void MGE_pollAndSwapBuffers(MGE_Window* window);


#endif //MATTS_GAME_ENGINE_DISPLAYS_H
