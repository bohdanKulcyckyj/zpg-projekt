#pragma once
#include "Subject.h"

#include <glm/mat4x4.hpp>

#define BASELIGHT 0
#define SPOTLIGHT 1
#define DIRECTIONALLIGHT 2
#define POINTLIGHT 3

class Light: public Subject
{
protected:
	int type = 0;
	glm::vec3 position;
	glm::vec4 color;
public: 
	Light(glm::vec3 pos, glm::vec4 col);
	glm::vec3 getPosition();
	glm::vec4 getColor();
	int getType();

	void notifyAll(int message) override;
};

