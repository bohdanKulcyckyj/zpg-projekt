#pragma once
#include "Scene.h"

class SceneForest : public Scene
{
public:
	SceneForest(GLFWwindow* w);
	void init() override;
};

