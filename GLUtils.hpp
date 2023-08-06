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

#endif /* GLUTILS_HPP_ */
