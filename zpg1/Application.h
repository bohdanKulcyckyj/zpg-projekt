#pragma once

#include <GL/glew.h>
//Include GLFW
#include <GLFW/glfw3.h> 

//Include GLM  
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr

// Models
#include "Scene.h"

#include <vector>

using namespace std;

class Application
{
private:
	static Application* instance;
	GLFWwindow* window;
	Scene* scene;

public:
	Application();
	// singleton instance
	static Application* getInstance();

	void initialization();
	void run();
};

