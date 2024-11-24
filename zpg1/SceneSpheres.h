#pragma once
#include "Scene.h"

class SceneSpheres : public Scene
{
public:
	SceneSpheres(GLFWwindow* w);
	void init() override;
};

