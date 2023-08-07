/*
 * GLUtils.hpp
 *
 *  Created on: Aug 5, 2023
 *      Author: Palanath
 */

#ifndef GLUTILS_HPP_
#define GLUTILS_HPP_

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

/*
 * Creates a shader with the specified type and source code, and compiles it.
 * Errors can be checked for with checkShadercompilationError(GLuint).
 */
GLuint createShader(GLenum shaderType, const char*);
/*
 * Checks if there are shader errors.
 * Returns true if there are and false otherwise.
 */
bool checkShaderCompilationError(GLuint);

/*
 * Attaches each of the provided shaders to the provided program via glAttachShader.
 */
template<typename ...Shader> void attachShaders(GLuint, Shader ...);

/*
 * Creates a shader program with the provided vertex and fragment shader code.
 * The vertex and fragment shaders are created, compiled, and bound to the program, then deleted after the program is finished being created.
 *
 * Errors in the vertex and fragment shaders are checked for after compilation and printed to the console.
 * If errors occur, the function returns nullptr.
 *
 * The program is not set to be used with glUseProgram.
 * This must be done by the caller, if desired.
 */
GLuint createShaderProgram(const char*, const char*);

template<typename ... Shader>
inline void attachShaders(GLuint program, Shader ... shaders) {
static_assert((std::is_same_v<GLuint, Shader> && ...));
(glAttachShader(program, shaders), ...);
}

/*
 * Sets the OpenGL viewport to the largest fitting square centered within the application window.
 *
 * The window width and height are determined through glfwGetFramebufferSize.
 * The values obtained through calling glfwGetFramebufferSize are provided to squareViewport(int, int)
 */
void squareViewport(GLFWwindow*);

/*
 * Sets the OpenGL viewport to the largest fitting square centered within the application window.
 *
 * The size and location of the square are calculated from the provided windowWidth and windowHeight.
 */
void squareViewport(int windowWidth, int windowHeight);

/*
 * A callback function that can be provided to glfwSetWindowSizeCallback.
 * This function will resize the viewport to be the largest fitting square any time the application window's size changes.
 * This function simply calls squareViewport with the window's framebuffer's width and height.
 */
void squareViewportGLFWCallback(GLFWwindow*, int, int);

/*
 * Initializes GLFW, creates a GLFW window, and initializes GLEW.
 * This function returns a pointer to the created GLFW window upon completion.
 * If enableDebug is true, this function will enable GL_DEBUG_OUTPUT.
 *
 * This function checks for failure when initializing GLFW, creating the window, and initializing GLEW.
 * If any are detected, this function returns a null pointer.
 * If a failure is detected and the window has already been created (successfully), this function destroys the window before returning a null pointer.
 */
GLFWwindow* initOpenGL(int, int, const char*, bool = true);

void GLAPIENTRY glDebugCallback(GLenum, GLenum, GLuint, GLenum, GLsizei,
	const GLchar*, const void*);

#endif /* GLUTILS_HPP_ */
