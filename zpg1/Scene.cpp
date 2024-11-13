#include <random>
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

void Scene::initModels() {
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<float> scale_dist(0.5f, 2.0f);
	std::uniform_real_distribution<float> rotate_dist(1.0f, 360.0f);
	std::uniform_real_distribution<float> translate_dist(-5.0f, 5.0f);

	int TREES_COUNT = 10;
	for (int i = 0; i < TREES_COUNT; i++) {
		ShaderProgram* tree_shaderProgram = new ShaderProgram(camera);
		TreeModel* tree = new TreeModel();
		tree_shaderProgram->loadShader("VertexShader.glsl", "FragmentShader.glsl");
		DrawableObject* obj_tree = new DrawableObject(tree_shaderProgram, tree);

		glm::vec3 scale(scale_dist(gen), scale_dist(gen), scale_dist(gen));
		float rotation_angle = rotate_dist(gen);
		glm::vec3 rotation_axis(0.0f, 1.0f, 0.0f);
		glm::vec3 translation(translate_dist(gen), 0.0f, translate_dist(gen));

		obj_tree->addTransform(new TransformScale(scale));
		obj_tree->addTransform(new TransformRotate(rotation_angle, rotation_axis));
		obj_tree->addTransform(new TransformTranslate(translation));

		this->objects.push_back(obj_tree);
		this->camera->attach(tree_shaderProgram);
	}
}