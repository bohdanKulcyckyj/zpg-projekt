#pragma once

#include "Light.h"

class PointLight : public Light
{
private:
    float constant;
    float linear;
    float quadratic;
    glm::vec4 ambient;
    glm::vec4 diffuse;
    glm::vec4 specular;
public:
    PointLight(float constant, float linear, float quadratic, glm::vec4 ambient, glm::vec4 diffuse, glm::vec4 specular, glm::vec3 position, glm::vec4 color);
    float getConstant();
    float getLinear();
    float getQuadratic();
    glm::vec4 getAmbient();
    glm::vec4 getDiffuse();
    glm::vec4 getSpecular();
};