#include "LightManager.h"

DirectionalLight* LightManager::addDirectionalLight(glm::vec3 direction, glm::vec4 ambient, glm::vec4 diffuse, glm::vec4 specular, glm::vec3 position, glm::vec4 color) {
	DirectionalLight* dl = new DirectionalLight(direction, ambient, diffuse, specular, position, color);
	this->lights.push_back(dl);
	this->lightsCount += 1;
	return dl;
}

SpotLight* LightManager::addSpotLight(glm::vec3 direction, float cutOff, float outerCutOff, float constant, float linear, float quadratic, glm::vec4 ambient, glm::vec4 diffuse, glm::vec4 specular, glm::vec3 position, glm::vec4 color) {
	SpotLight* sl = new SpotLight(direction, cutOff, outerCutOff, constant, linear, quadratic, ambient, diffuse, specular, position, color);
	this->lights.push_back(sl);
	this->lightsCount += 1;
	return sl;
}

PointLight* LightManager::addPointLight(float constant, float linear, float quadratic, glm::vec4 ambient, glm::vec4 diffuse, glm::vec4 specular, glm::vec3 position, glm::vec4 color) {
	PointLight* pl = new PointLight(constant, linear, quadratic, ambient, diffuse, specular, position, color);
	this->lights.push_back(pl);
	this->lightsCount += 1;
	return pl;
}

Light* LightManager::addLight(glm::vec3 position, glm::vec4 color) {
	Light* l = new Light(position, color);
	this->lights.push_back(l);
	this->lightsCount += 1;
	return l;
}

Light* LightManager::getLight(int index) {
	if (index >= 0 && lightsCount >= index + 1) {
		return lights.at(index);
	}
	throw exception("Index out of range");
}