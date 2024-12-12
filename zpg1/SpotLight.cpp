#include "SpotLight.h"

SpotLight::SpotLight(glm::vec3 dir, float cutOff, float outerCutOff, float constant, float linear, float quadratic, glm::vec4 ambient, glm::vec4 diffuse, glm::vec4 specular, glm::vec3 position, glm::vec4 color)
    : Light(position, color)
{
    this->type = SPOTLIGHT;
    this->direction = dir;
    this->cutOff = cutOff;
    this->outerCutOff = outerCutOff;
    this->constant = constant;
    this->linear = linear;
    this->quadratic = quadratic;
    this->ambient = ambient;
    this->diffuse = diffuse;
    this->specular = specular;
}

glm::vec3 SpotLight::getDirection() {
    return this->direction;
}
float SpotLight::getCutOff()
{
    return this->cutOff;
}
float SpotLight::getOuterCutOff()
{
    return this->outerCutOff;
}
float SpotLight::getConstant() {
    return this->constant;
}
float SpotLight::getLinear() {
    return this->linear;
}
float SpotLight::getQuadratic() {
    return this->quadratic;
}
glm::vec4 SpotLight::getAmbient() {
    return this->ambient;
}
glm::vec4 SpotLight::getDiffuse() {
    return this->diffuse;
}
glm::vec4 SpotLight::getSpecular() {
    return this->specular;
}

void SpotLight::updateDirection(glm::vec3 direction)
{
    this->direction = direction;
}

void SpotLight::updatePosition(glm::vec3 pos)
{
    this->position = pos;
}