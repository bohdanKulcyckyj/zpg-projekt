#include "Shader.h"
#include <stdlib.h>

Shader::Shader(GLuint id, const char* source) {
	this->shaderId = id;
	glShaderSource(id, 1, &source, NULL);
	glCompileShader(id);
}