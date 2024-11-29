#include "Light.h"

Light::Light(glm::vec3 pos, glm::vec4 col) {
	position = pos;
	color = col;

	this->notifyAll(LIGHTCOLOR);
	this->notifyAll(LIGHTPOSITION);
}

glm::vec3 Light::getPosition() {
	return position;
}

glm::vec4 Light::getColor() {
	return color;
}

int Light::getType() {
	return type;
}

void Light::notifyAll(int message) {
	for (auto o : observers) {
		o->update(message);
	}
}