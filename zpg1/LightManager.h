#pragma once
#include <vector>
#include <iostream>

#include "Light.h"
#include "SpotLight.h"
#include "SpotLightCamera.h"
#include "PointLight.h"
#include "DirectionalLight.h"

using namespace std;

class LightManager
{
private:
	vector<Light*> lights;
public:
	DirectionalLight* addDirectionalLight(glm::vec3 direction, glm::vec4 ambient, glm::vec4 diffuse, glm::vec4 specular, glm::vec3 position, glm::vec4 color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
	SpotLight* addSpotLight(glm::vec3 direction, float cutOff, float outerCutOff, float constant, float linear, float quadratic, glm::vec4 ambient, glm::vec4 diffuse, glm::vec4 specular, glm::vec3 position, glm::vec4 color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
	PointLight* addPointLight(float constant, float linear, float quadratic, glm::vec4 ambient, glm::vec4 diffuse, glm::vec4 specular, glm::vec3 position, glm::vec4 color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));
	Light* addLight(glm::vec3 position, glm::vec4 color = glm::vec4(1.0f, 1.0f, 1.0f, 1.0f));

	Light* getLight(int index);
	int lightsCount = 0;
};

