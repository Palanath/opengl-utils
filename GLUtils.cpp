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
		return 0;
	auto prog = glCreateProgram();
	attachShaders(prog, vert, frag);
	glLinkProgram(prog);
	return prog;
}

void squareViewport(int windowWidth, int windowHeight) {
	if (windowWidth > windowHeight)
		glViewport((windowWidth - windowHeight) / 2, 0, windowHeight,
				windowHeight);
	else
		glViewport(0, (windowHeight - windowWidth) / 2, windowWidth,
				windowWidth);
}

void squareViewportGLFWCallback(GLFWwindow *win, int, int) {
	int w, h;
	glfwGetFramebufferSize(win, &w, &h);
	squareViewport(w, h);
}

GLFWwindow* initOpenGL(int windowWidth, int windowHeight,
		const char *windowName, bool enableDebug) {
	if (!glfwInit())
		return nullptr;
	GLFWwindow *win = glfwCreateWindow(windowWidth, windowHeight, windowName,
			nullptr, nullptr);
	if (!win)
		return nullptr;
	glfwMakeContextCurrent(win);
	if (glewInit() != GLEW_OK) {
		return nullptr;
		glfwDestroyWindow(win);
	}
	glEnable(GL_DEBUG_OUTPUT);
	return win;

}
