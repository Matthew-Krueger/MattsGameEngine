//
// Created by matth on 10/24/20.
//

#ifndef MATTS_GAME_ENGINE_GRAPHICSAPI_H
#define MATTS_GAME_ENGINE_GRAPHICSAPI_H

#include "../Utils/UtilsInternal.h"

struct MGE_Window;
struct MGE_ShaderProgram;


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
MGE_API void MGE_windowFinalize(struct MGE_Window* window);


/**
 * Prepares the frame for rendering by clearing the color buffer bit and setting a default color
 */
MGE_API void MGE_prepareFrame();

/**
 * Renders a raw model to the display
 * @param model The model to render
 */
MGE_API void MGE_renderRawModel(struct MGE_RawModel model);

/**
 *
 * Loads a shader into GPU memory from the disk.
 * @param vertexShaderPath The path to the Vertex Shader source
 * @param fragmentShaderPath The path to the Fragment Shader source
 * @return The Shader Program
 * @param bindAttributes The lambda to bind attributes in the program
 * @return
 */
MGE_API struct MGE_ShaderProgram* MGE_shaderLoadProgramFromFiles(const char* vertexShaderPath, const char* fragmentShaderPath, void (*bindAttributes)(struct MGE_ShaderProgram*));

/**
 * Loads a shader into GPU memory from CPU memory
 * @param vertexSource The Vertex Shader source to attach
 * @param fragmentSource The Fragment Shader source to attach
 * @return The shader program
 */
MGE_API struct MGE_ShaderProgram* MGE_shaderCompileFromTargetProgram(struct MGE_ShaderProgram* target);

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
MGE_API void MGE_freeShaderProgram(struct MGE_ShaderProgram* shaderProgram);

/**
 * Binds an attribute to a part of the shader
 * @param shaderProgram The shader program to bind to.
 * @param attribute The attribute number to bind.
 * @param variableName The variable name to bind the attribute to.
 */
MGE_API void MGE_shaderBindAttribute(struct MGE_ShaderProgram* shaderProgram, GLuint attribute, const char* variableName);

#endif //MATTS_GAME_ENGINE_GRAPHICSAPI_H
