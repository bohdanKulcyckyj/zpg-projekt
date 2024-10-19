#pragma once

#include <GL/glew.h>

#include "Shader.h"
#include <vector>

using namespace std;

class ShaderProgram
{
private:
	GLuint programId;
	std::vector<GLuint> shaderIds;
public:
    ShaderProgram();
    ~ShaderProgram();

    Shader* addShader(int type, const char* source);
    void createProgram();
    void use();
};

