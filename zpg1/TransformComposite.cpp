#include "TransformComposite.h"

void TransformComposite::addTransform(Transform* t)
{
	this->transforms.push_back(t);
}

glm::mat4 TransformComposite::computeTransform() {
	this->matrix = glm::mat4(1.0f);

	for (auto t : transforms)
	{
		this->matrix *= t->computeTransform();
	}

	return this->matrix;
}