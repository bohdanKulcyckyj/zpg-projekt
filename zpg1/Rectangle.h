#pragma once
#include "Vertex.h"
#include "BaseModel.h"

class Rectangle : public BaseModel
{
public:
	Rectangle(Vertex* points, size_t pointsSize, ShaderProgram* sp);
	void draw() override;
};

