#include "Scene.h"

Scene::Scene(GLFWwindow* window) {
	this->window = window;
	this->camera = new Camera(window);
}

void Scene::registerCallbacks() {
	glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
		Controller::getInstance()->onKey(window, key, scancode, action, mods);
		});

	glfwSetCursorPosCallback(window, [](GLFWwindow* window, double x, double y) {
		Controller::getInstance()->onCursor(window, x, y);
		});

	glfwSetMouseButtonCallback(window, [](GLFWwindow* window, int button, int action, int mods) {
		Controller::getInstance()->onButton(window, button, action, mods);
		});

	glfwSetWindowFocusCallback(window, [](GLFWwindow* window, int focused) {
		Controller::getInstance()->onWindowFocus(window, focused);
		});

	glfwSetWindowIconifyCallback(window, [](GLFWwindow* window, int iconified) {
		Controller::getInstance()->onWindowIconify(window, iconified);
		});

	glfwSetWindowSizeCallback(window, [](GLFWwindow* window, int width, int height) {
		Controller::getInstance()->onWindowResize(window, width, height);
		});
}

void Scene::render() {
	glEnable(GL_DEPTH_TEST);

	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		camera->checkForChanges();
		camera->controls();

		for (auto obj : this->objects) {
			obj->draw();
		}

		glfwPollEvents();
		glfwSwapBuffers(window);
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}