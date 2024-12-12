#pragma once

#include <GL/glew.h>

#include "Observer.h"
#include "ShaderLoader.h"
#include "Camera.h"
//#include "Light.h"
#include "LightManager.h"
#include <vector>

using namespace std;

class ShaderProgram : public Observer, public ShaderLoader
{
private:
    Camera* camera = nullptr;
    LightManager* lightManager = nullptr;
    //GLuint	shaderProgramID = 0;
public:
    ShaderProgram(Camera* c, const char* vertexFile, const char* fragmentFile);
    ShaderProgram(Camera* c, LightManager* lm, const char* vertexFile, const char* fragmentFile);
    ~ShaderProgram();

    void setLightManager(LightManager* l);
    void updateLights();
    void updatePointLights();
    void updateDirectionalLight();
    void updateSpotLight();
    void updateLight();

    void use();
    void unuse();

    void updateUniform(const char* variable, const GLfloat* value);
    void updateUniform(const char* variable, glm::vec3 value);
    void updateUniform(const char* variable, glm::vec4 value);
    void updateUniform(const char* variable, float value);
    void updateUniform(const char* variable, int value);
    // observers update method
    void update(int message) override;
};

