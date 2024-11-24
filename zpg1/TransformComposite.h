#pragma once

#include <vector>
#include "Transform.h"

using namespace std;

// nemusi se vsechny transformace nutne vsechny prepocitavat

class TransformComposite: public Transform
{
private:
	vector<Transform*> transforms;
public:
	void addTransform(Transform* t);
	glm::mat4 computeTransform();
};

