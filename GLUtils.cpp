/*
 * GLUtils.cpp
 *
 *  Created on: Aug 5, 2023
 *      Author: Palanath
 */

#include "GLUtils.hpp"

GLuint createShader(GLenum shaderType, const char *source) {
	GLuint res = glCreateShader(shaderType);
	glShaderSource(res, 1, &source, nullptr);
	glCompileShader(shaderType);
	return res;
}

bool checkShaderCompilationError(GLuint shader) {
	int success;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	return success;
}
