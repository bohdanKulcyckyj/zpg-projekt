#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>

#define ASSERT(x) if (!(x)) __debugbreak();

class OpenGLDebugWrapper
{
public:
	static bool glLogCall(const char* file, const char* function, int line) {
		bool isSuccess = true;
		while (GLenum error = glGetError()) {
			isSuccess = false;
			std::cout << "[OpenGL Error] (" << error << ")" << " in "
				<< file << " > " << function << " line: " << line << std::endl;
		}
		return isSuccess;
	}

	static void glClearError() {
		while (glGetError() != GL_NO_ERROR);
	}
};

#define WITH_DEBUG(x) OpenGLDebugWrapper::glClearError();\
	x;\
	ASSERT(OpenGLDebugWrapper::glLogCall(__FILE__, #x, __LINE__))

