#pragma once
#include "Vertex.h"
#include "Model.h"

class Rectangle : public Model
{
public:
	Rectangle(Vertex* points, size_t pointsSize);
	void draw() override;
};

