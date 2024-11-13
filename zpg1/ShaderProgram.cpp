#include "ShaderProgram.h"
#include "Shader.h"
#include <iostream>

ShaderProgram::ShaderProgram(Camera* c) : ShaderLoader() {
    camera = c;
}

ShaderProgram::~ShaderProgram() {
    glDeleteProgram(shaderProgramID);
}

void ShaderProgram::use() {
    glUseProgram(shaderProgramID);
}

void ShaderProgram::unuse() {
    glUseProgram(0);
}

void ShaderProgram::update(int message)
{
    if (message == VIEWMATRIX)
    {
        printf("updating view matrix\n");
        use();
        updateUniform("viewMatrix", glm::value_ptr(camera->getViewMatrix()));
        updateUniform("position", camera->getPosition());
        updateUniform("cameraDirection", camera->getDirection());
        unuse();

        return;
    }

    if (message == PROJECTIONMATRIX)
    {
        printf("updating projection matrix\n");
        use();
        updateUniform("projectionMatrix", glm::value_ptr(camera->getProjectionMatrix()));
        unuse();

        return;
    }

    throw exception("Unknown message");
}

void ShaderProgram::updateUniform(const char* variable, const GLfloat* value)
{
    GLint location = glGetUniformLocation(shaderProgramID, variable);

    if (location >= 0)
    {
        glUniformMatrix4fv(location, 1, GL_FALSE, value);
    }
}

void ShaderProgram::updateUniform(const char* variable, glm::vec3 value)
{
    GLint location = glGetUniformLocation(shaderProgramID, variable);

    if (location >= 0)
    {
        glUniform3f(location, value.x, value.y, value.z);
    }
}

void ShaderProgram::updateUniform(const char* variable, float value)
{
    GLint location = glGetUniformLocation(shaderProgramID, variable);

    if (location >= 0)
    {
        glUniform1f(location, value);
    }
}

void ShaderProgram::updateUniform(const char* variable, int value)
{
    GLint location = glGetUniformLocation(shaderProgramID, variable);

    if (location >= 0)
    {
        glUniform1i(location, value);
    }
}