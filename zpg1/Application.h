#pragma once
//Include GLFW  
#include <GL/glew.h>
#include <GLFW/glfw3.h>  
//Include GLM  
#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/gtc/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale, glm::perspective
#include <glm/gtc/type_ptr.hpp> // glm::value_ptr
//Include the standard C++ headers  
#include <stdlib.h>
#include <stdio.h>

static void error_callback(int error, const char* description) { fputs(description, stderr); }

float points[] = {
	 0.0f, 0.5f, 0.0f,
	 0.5f, -0.5f, 0.0f,
	-0.5f, -0.5f, 0.0f
};

const char* vertex_shader =
"#version 330\n"
"layout(location=0) in vec3 vp;"
"void main () {"
"     gl_Position = vec4 (vp, 1.0);"
"}";

const char* fragment_shader =
"#version 330\n"
"out vec4 frag_colour;"
"void main () {"
"     frag_colour = vec4 (0.5, 0.0, 0.5, 1.0);"
"}";

class Application
{
private:
	GLFWwindow* window;
	GLuint VAO = 0;
	GLuint VBO = 0;
	GLuint shaderProgram;
public:
	void cursor_pos_callback(GLFWwindow* window, double mouseX, double mouseY);
	void initialization();
	void createShaders();
	//void createModels();
	void run();
};

