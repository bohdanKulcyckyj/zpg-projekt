#pragma once
#include "Model.h"
#include "sphere.h"

class SphereModel : public Model
{
public:
	SphereModel();
	void draw() override;
};

