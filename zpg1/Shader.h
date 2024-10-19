#pragma once

#include <GL/glew.h>
//Include GLFW
#include <GLFW/glfw3.h> 

class Shader
{
private:
	GLuint shaderId;
public:
	Shader(GLuint id, const char* source);
};

