#include "Material.h"

Material::Material(glm::vec4 ambient, glm::vec4 diffuse, glm::vec4 specularStrength, float specularIntensity, glm::vec4 objectColor)
{
	this->ambient = ambient;
	this->diffuse = diffuse;
	this->specularStrength = specularStrength;
	this->specularIntensity = specularIntensity;
	this->objectColor = objectColor;
}
Material::Material()
{
	this->ambient = glm::vec4(0.1, 0.1, 0.1, 1.0);
	this->diffuse = glm::vec4(0.385, 0.647, 0.812, 1.0);
	this->specularStrength = glm::vec4(1.0, 1.0, 1.0, 1.0);
	this->objectColor = glm::vec4(0.91, 0.47, 0.65, 1.0);
	this->specularIntensity = 16;
}
glm::vec4 Material::getAmbient() {
	return this->ambient;
}
glm::vec4 Material::getDiffuse() {
	return this->diffuse;
}
glm::vec4 Material::getSpecularStrength() {
	return this->specularStrength;
}
float Material::getSpecIntensity() {
	return this->specularIntensity;
}
glm::vec4 Material::getObjColor() {
	return this->objectColor;
}