#include "Controller.h"

Controller* Controller::instance = nullptr;

Controller* Controller::getInstance() {
	return instance;
}

Controller::Controller() {
	instance = this;
}

void Controller::onError(int error, const char* description) {
	fputs(description, stderr);
}

void Controller::onKey(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, GL_TRUE);
	}
	printf("key_callback [%d,%d,%d,%d] \n", key, scancode, action, mods);
}

void Controller::onWindowFocus(GLFWwindow* window, int focused) {
	printf("onWindowFocus callback \n");
}

void Controller::onWindowIconify(GLFWwindow* window, int iconified) {
	printf("onWindowIconify callback \n");
}

void Controller::onWindowResize(GLFWwindow* window, int width, int height) {
	printf("resize %d, %d \n", width, height);
	glViewport(0, 0, width, height);
}

void Controller::onCursor(GLFWwindow* window, double x, double y) {
	printf("onCursor callback \n");
}

void Controller::onButton(GLFWwindow* window, int button, int action, int mode) {
	if (action == GLFW_PRESS) printf("onButton callback [%d,%d,%d]\n", button, action, mode);
}