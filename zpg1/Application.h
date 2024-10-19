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
#include "Triangle.h"
#include "Rectangle.h"

#include "Vertex.h"

#include <vector>

using namespace std;

class Application
{
private:
	static Application* instance;
	GLFWwindow* window;
	vector<BaseModel*> models;

public:
	Application();
	// singleton instance
	static Application* getInstance();

	// callbacks
	void onError(int error, const char* description);
	void onKey(GLFWwindow* window, int key, int scancode, int action, int mods);
	void onWindowFocus(GLFWwindow* window, int focused);
	void onWindowIconify(GLFWwindow* window, int iconified);
	void onWindowResize(GLFWwindow* window, int width, int height);
	void onCursor(GLFWwindow* window, double x, double y);
	void onButton(GLFWwindow* window, int button, int action, int mode);

	void initialization();
	void createModels();
	void run();
};

