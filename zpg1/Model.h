#pragma once
#include "ShaderProgram.h"

class Model
{
protected:
	GLuint VAO = 0;
	GLuint VBO = 0;

public:
	Model();
	virtual void draw() = 0;
};

