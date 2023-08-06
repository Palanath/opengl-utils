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

namespace {
/*
 * Prints shader errors.
 * Returns true if errors were found and printed.
 */
bool printShaderErrors(GLuint shader, const char *shaderType) {
	if (checkShaderCompilationError(shader)) {
		char errlog[512];
		glGetShaderInfoLog(shader, 512, NULL, errlog);
		std::cout << shaderType << " shader compilation error: \n" << errlog
				<< std::endl;
		return true;
	}
	return false;
}
}

GLuint createShaderProgram(const char *vertexShaderSource,
		const char *fragmentShaderSource) {
	auto vert = createShader(GL_VERTEX_SHADER, vertexShaderSource), frag =
			createShader(GL_FRAGMENT_SHADER, fragmentShaderSource);
	if (printShaderErrors(vert, "Vertex") | printShaderErrors(frag, "Fragment"))
		return nullptr;
	auto prog = glCreateProgram();
	glAttachShader(prog, vert);
	glAttachShader(prog, frag);
	glLinkProgram(prog);
	return prog;
}
