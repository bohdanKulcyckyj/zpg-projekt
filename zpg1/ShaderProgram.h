#pragma once

#include <GL/glew.h>

#include "Observer.h"
#include "ShaderLoader.h"
#include "Camera.h"
#include "Light.h"
#include <vector>

using namespace std;

class ShaderProgram : public Observer, public ShaderLoader
{
private:
    Camera* camera = nullptr;
    Light* light = nullptr;
public:
    ShaderProgram(Camera* c);
    ShaderProgram(Camera* c, Light* l);
    ~ShaderProgram();

    void addLight(Light* l);

    void use();
    void unuse();

    void updateUniform(const char* variable, const GLfloat* value);
    void updateUniform(const char* variable, glm::vec3 value);
    void updateUniform(const char* variable, float value);
    void updateUniform(const char* variable, int value);
    // observers update method
    void update(int message) override;
};

