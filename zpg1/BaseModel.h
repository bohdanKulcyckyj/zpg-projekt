#pragma once
#include "ShaderProgram.h"

class BaseModel
{
protected:
	ShaderProgram* shaderProgram;
	GLuint VAO = 0;
	GLuint VBO = 0;

public:
	BaseModel(ShaderProgram* sp);
	virtual void draw() = 0;
};

