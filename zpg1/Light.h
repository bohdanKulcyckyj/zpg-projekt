#pragma once
#include "Subject.h"

#include <glm/mat4x4.hpp>

class Light: public Subject
{
	glm::vec3 position;
	glm::vec4 color;
public: 
	Light(glm::vec3 pos, glm::vec4 col);
	glm::vec3 getPosition();
	glm::vec4 getColor();

	void notifyAll(int message) override;
};

