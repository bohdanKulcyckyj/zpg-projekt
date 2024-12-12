#pragma once
#include <glm/vec3.hpp>
#include <glm/vec4.hpp>

#include <stdlib.h>
#include <stdio.h>
#include <string>

class Material
{
private:
	glm::vec4 ambient;
	glm::vec4 diffuse;
	glm::vec4 specularStrength;
	float specularIntensity;
	glm::vec4 objectColor;

public:
	Material(glm::vec4 ambient, glm::vec4 diffuse, glm::vec4 specularStrength, float specularIntensity, glm::vec4 objectColor);
	Material();
	glm::vec4 getAmbient();
	glm::vec4 getDiffuse();
	glm::vec4 getSpecularStrength();
	glm::vec4 getObjColor();
	float getSpecIntensity();
};
