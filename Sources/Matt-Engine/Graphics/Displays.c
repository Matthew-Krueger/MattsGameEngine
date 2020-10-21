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

#include "Displays.h"
#include <stdio.h>


MGE_Window* MGE_initWindow(int width, int height, const char* windowName) {
    MGE_Window* window = (MGE_Window*) malloc(sizeof(MGE_Window));

    /* Init glfw and crash if unable */
    if(!glfwInit()){
        glfwTerminate();
        MGE_CORE_LOG_CRITICAL("Failed to start GLFW","glfwInit() returned other than true",1);
    }

    /* Do window hints for GLFW */
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    window->window = glfwCreateWindow(width, height, windowName, NULL, NULL);
    if(!window->window){
        glfwTerminate();
        MGE_CORE_LOG_CRITICAL("Failed to create a GL Window context.","",3);
    }

    glfwMakeContextCurrent(window->window);

    /* Init GLAD */
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        MGE_CORE_LOG_CRITICAL("Failed to load OpenGL with GLAD", "Glad GLL Loader could not get address of function pointers.",3);
    }

    /* Set glViewport to what we were given */
    glViewport(0, 0, width, height);

    MGE_setWindowResizeCallback(window, framebufferSizeCallback);

    return window;
}

void MGE_deleteWindow(MGE_Window *window) {

    glfwTerminate();
    free(window);

}


bool MGE_windowShouldClose(MGE_Window* window){
    return glfwWindowShouldClose(window->window);
}

void MGE_pollAndSwapBuffers(MGE_Window *window) {

    /* Swap buffers */
    glfwSwapBuffers(window->window);

    glfwPollEvents();

}
