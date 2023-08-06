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
GLuint createShader(GLenum shaderType, const char *source);
/*
 * Checks if there are shader errors.
 * Returns true if there are and false otherwise.
 */
bool checkShaderCompilationError(GLuint shader);

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
GLuint createShaderProgram(const char *vertexShaderSource,
		const char *fragmentShaderSource);

#endif /* GLUTILS_HPP_ */
