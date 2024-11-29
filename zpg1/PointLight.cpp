#include "PointLight.h"

PointLight::PointLight(float constant, float linear, float quadratic, glm::vec4 ambient, glm::vec4 diffuse, glm::vec4 specular, glm::vec3 position, glm::vec4 color)
    : Light(position, color)
{
    this->type = POINTLIGHT;
    this->constant = constant;
    this->linear = linear;
    this->quadratic = quadratic;
    this->ambient = ambient;
    this->diffuse = diffuse;
    this->specular = specular;
}

float PointLight::getConstant() {
    return this->constant;
}
float PointLight::getLinear() {
    return this->linear;
}
float PointLight::getQuadratic() {
    return this->quadratic;
}
glm::vec4 PointLight::getAmbient() {
    return this->ambient;
}
glm::vec4 PointLight::getDiffuse() {
    return this->diffuse;
}
glm::vec4 PointLight::getSpecular() {
    return this->specular;
}