#pragma once

#include "BaseModel.h"

class Triangle : public BaseModel
{
public:
	Triangle(float* points, size_t pointsSize, ShaderProgram* sp);
	void draw() override;
};

