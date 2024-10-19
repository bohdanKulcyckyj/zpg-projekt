#include "ShaderProgram.h"
#include "Shader.h"
#include <iostream>

void ShaderProgram::createProgram() {
    programId = glCreateProgram();
    for (auto shaderId : this->shaderIds) {
        glAttachShader(programId, shaderId);
    }

    glLinkProgram(programId);

    GLint status;
    glGetProgramiv(programId, GL_LINK_STATUS, &status);
    if (status == GL_FALSE)
    {
        GLint infoLogLength;
        glGetProgramiv(programId, GL_INFO_LOG_LENGTH, &infoLogLength);
        GLchar* strInfoLog = new GLchar[infoLogLength + 1];
        glGetProgramInfoLog(programId, infoLogLength, NULL, strInfoLog);
        fprintf(stderr, "Linker failure: %s\n", strInfoLog);
        delete[] strInfoLog;
    }
}

ShaderProgram::ShaderProgram() {}

ShaderProgram::~ShaderProgram() {
    glDeleteProgram(programId);
}

Shader* ShaderProgram::addShader(int type, const char* source) {
    GLuint shaderId = glCreateShader(type);
    Shader* shader = new Shader(shaderId, source);
    shaderIds.push_back(shaderId);

    return shader;
}

void ShaderProgram::use() {
    glUseProgram(programId);
}
