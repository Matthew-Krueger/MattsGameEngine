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

#ifndef MATTS_GAME_ENGINE_GRAPHICSAPI_H
#define MATTS_GAME_ENGINE_GRAPHICSAPI_H

#include "../EngineForwardDecls.h"

/**
 * Initialize a GL Context with a width, height, and windowName
 * @param width The Width of the new window to create.
 * @param height The height of the new window to create.
 * @param windowName The name of the window to create
 * @return {\link MGE_Window MGE_Window* \endlink}, a representation of the GLFWwindow
 */
MGE_API struct MGE_Window* MGE_windowInit(int width, int height, const char* windowName);

/**
 * Delete the memory and GL context associated with a window
 * @param window
 */
MGE_API void MGE_windowDelete(struct MGE_Window* window);

/**
 * Tests if a window should close
 * @param window The window to check
 * @return bool on whether the window should close
 */
MGE_API bool MGE_windowShouldClose(struct MGE_Window* window);

MGE_API void MGE_windowSetShouldClose(struct MGE_Window* window);

/**
 * Poll OpenGL for updates and swap the front and back buffers
 * @param window The MGE_Window to do this to
 */
MGE_API void MGE_windowUpdate(struct MGE_Window* window);


/**
 * Prepares the frame for rendering by clearing the color buffer bit and setting a default color
 */
MGE_API void MGE_prepareFrame();

/**
 * Renders a raw model to the display
 * @param model The model to render
 */
MGE_API void MGE_renderRawModel(struct MGE_RawModel* model);

MGE_API void MGE_renderTexturedModel(struct MGE_TexturedModel* model);

/**
 *
 * Loads a shader into GPU memory from the disk.
 * @param vertexShaderPath The path to the Vertex Shader source
 * @param fragmentShaderPath The path to the Fragment Shader source
 * @return The Shader Program
 * @param bindAttributes The lambda to bind attributes in the program
 * @return
 */
MGE_API struct MGE_ShaderProgram* MGE_shaderLoadProgramFromFiles(const char* vertexShaderPath, const char* fragmentShaderPath, void (*bindAttributes)(struct MGE_ShaderProgram*), void (*getAllUniformLocations)(struct MGE_ShaderProgram*));

/**
 * Loads a shader into GPU memory from CPU memory
 * @param vertexSource The Vertex Shader source to attach
 * @param fragmentSource The Fragment Shader source to attach
 * @return The shader program
 */
MGE_API struct MGE_ShaderProgram* MGE_shaderCompileFromTargetProgram(struct MGE_ShaderProgram* target, void (*bindAttributes)(struct MGE_ShaderProgram*));

/**
 * Gets the location of a uniform variable
 * @param target The shader to bind a uniform variable to
 * @param uniformName The name of the uniform variable
 * @return The uniform value.
 */
MGE_API GLint MGE_shaderGetUniformLocation(struct MGE_ShaderProgram* target, const char * uniformName);

/**
 * Load a float to a shader uniform
 * @param location The location to load the float to
 * @param value The value to load
 */
MGE_API void MGE_shaderLoadFloat(GLint location, GLfloat value);

/**
 * Load a vec3 to the shader uniform
 * @param location The location to load it to
 * @param vector The vector to load
 */
MGE_API void MGE_shaderLoadVec3(GLint location, vec3 vector);

/**
 * Loads a bool to a shader
 * @param location The location to load it to
 * @param value The value to load
 */
MGE_API void MGE_shaderLoadBol(GLint location, bool value);

/**
 * Does a location 
 * @param location
 * @param matrixToLoad
 */
MGE_API void MGE_shaderLoadMat4x4f(GLint location, mat4x4 matrixToLoad);

/**
 * Tell OpenGL to use a Shader Program
 * @param shaderProgram The Shader Program to use
 */
MGE_API void MGE_shaderStart(struct MGE_ShaderProgram* shaderProgram);

/**
 * Tell OpenGL to no longer use a shader
 */
MGE_API void MGE_shaderStop();


/**
 * Frees a shader program and deletes everything from memory
 * @param shaderProgram The shader program to delete
 */
MGE_API void MGE_shaderProgramFree(struct MGE_ShaderProgram* shaderProgram);

/**
 * Binds an attribute to a part of the shader
 * @param shaderProgram The shader program to bind to.
 * @param attribute The attribute number to bind.
 * @param variableName The variable name to bind the attribute to.
 */
MGE_API void MGE_shaderBindAttribute(struct MGE_ShaderProgram* shaderProgram, GLuint attribute, const char* variableName);

#endif //MATTS_GAME_ENGINE_GRAPHICSAPI_H
