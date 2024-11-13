#pragma once

#include "Model.h"

class Triangle : public Model
{
public:
	Triangle(float* points, size_t pointsSize);
	void draw() override;
};

