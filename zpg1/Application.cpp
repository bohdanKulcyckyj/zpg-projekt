#include "Application.h"

Application* Application::instance = nullptr;

Application* Application::getInstance() {
	return instance;
}

Application::Application() {
	instance = this;
}

// Callbacks
void Application::onError(int error, const char* description) {
	fputs(description, stderr);
}

void Application::onKey(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, GL_TRUE);
	}
	printf("key_callback [%d,%d,%d,%d] \n", key, scancode, action, mods);
}

void Application::onWindowFocus(GLFWwindow* window, int focused) {
	printf("onWindowFocus callback \n");
}

void Application::onWindowIconify(GLFWwindow* window, int iconified) {
	printf("onWindowIconify callback \n");
}

void Application::onWindowResize(GLFWwindow* window, int width, int height) {
	printf("resize %d, %d \n", width, height);
	glViewport(0, 0, width, height);
}

void Application::onCursor(GLFWwindow* window, double x, double y) {
	printf("onCursor callback \n");
}

void Application::onButton(GLFWwindow* window, int button, int action, int mode) {
	if (action == GLFW_PRESS) printf("onButton callback [%d,%d,%d]\n", button, action, mode);
}

void Application::initialization() {
	// int error, const char* description
	glfwSetErrorCallback([](int error, const char* description) {
		Application::getInstance()->onError(error, description);
		});
	if (!glfwInit()) {
		fprintf(stderr, "ERROR: could not start GLFW3\n");
		exit(EXIT_FAILURE);
	}

	this->window = glfwCreateWindow(800, 600, "ZPG", NULL, NULL);
	if (!window) {
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);

	// start GLEW extension handler
	glewExperimental = GL_TRUE;
	glewInit();


	// get version info
	printf("OpenGL Version: %s\n", glGetString(GL_VERSION));
	printf("Using GLEW %s\n", glewGetString(GLEW_VERSION));
	printf("Vendor %s\n", glGetString(GL_VENDOR));
	printf("Renderer %s\n", glGetString(GL_RENDERER));
	printf("GLSL %s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));
	int major, minor, revision;
	glfwGetVersion(&major, &minor, &revision);
	printf("Using GLFW %i.%i.%i\n", major, minor, revision);

	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	float ratio = width / (float)height;
	glViewport(0, 0, width, height);

	glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
		Application::getInstance()->onKey(window, key, scancode, action, mods);
	});

	glfwSetCursorPosCallback(window, [](GLFWwindow* window, double x, double y) {
		Application::getInstance()->onCursor(window, x, y);
	});

	glfwSetMouseButtonCallback(window, [](GLFWwindow* window, int button, int action, int mods) {
		Application::getInstance()->onButton(window, button, action, mods);
	});

	glfwSetWindowFocusCallback(window, [](GLFWwindow* window, int focused) {
		Application::getInstance()->onWindowFocus(window, focused);
	});

	glfwSetWindowIconifyCallback(window, [](GLFWwindow* window, int iconified) {
		Application::getInstance()->onWindowIconify(window, iconified);
	});

	glfwSetWindowSizeCallback(window, [](GLFWwindow* window, int width, int height) {
		Application::getInstance()->onWindowResize(window, width, height);
	});
}

void Application::run() {
	while (!glfwWindowShouldClose(window)) {
		// clear color and depth buffer
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		for (auto model : this->models) {
			model->draw();
		}

		glfwPollEvents();
		// put the stuff we’ve been drawing onto the display
		glfwSwapBuffers(window);
	}

	glfwDestroyWindow(window);

	glfwTerminate();
	exit(EXIT_SUCCESS);
}

void Application::createModels() {
	float trianglePoints[] = {
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
		"     frag_colour = vec4 (255, 0.1, 0.1, 1.0);"
		"}";

	ShaderProgram* triangle1_shaderProgram = new ShaderProgram();
	Triangle* triangle1 = new Triangle(trianglePoints, sizeof(trianglePoints), triangle1_shaderProgram);
	triangle1_shaderProgram->addShader(GL_FRAGMENT_SHADER, fragment_shader);
	triangle1_shaderProgram->addShader(GL_VERTEX_SHADER, vertex_shader);
	triangle1_shaderProgram->createProgram();
	this->models.push_back(triangle1);

	Vertex rectangleVertices[] = {
		{ {0.9f, 0.9f, 0.0f}, {0.0f, 0.0f, 1.0f, 1.0f} },
		{ {0.9f, 0.5f, 0.0f}, {0.5f, 0.0f, 0.5f, 1.0f} },
		{ {0.5f, 0.5f, 0.0f}, {1.0f, 1.0f, 0.0f, 1.0f} },
		{ {0.5f, 0.9f, 0.0f}, {1.0f, 0.5f, 0.0f, 1.0f} },
		{ {0.9f, 0.9f, 0.0f}, {0.0f, 1.0f, 1.0f, 1.0f} },
		{ {0.5f, 0.5f, 0.0f}, {1.0f, 0.0f, 0.0f, 1.0f} }
	};


	const char* fragment_shader_color =
		"#version 330\n"
		"in vec4 fragColor;\n"
		"out vec4 outColor;\n"
		"void main () {\n"
		"    outColor = fragColor;\n"
		"}";

	const char* vertex_shader_color =
		"#version 330\n"
		"layout(location=0) in vec3 vp;\n"
		"layout(location=1) in vec4 vertexColor;\n"
		"out vec4 fragColor;\n"
		"void main () {\n"
		"    gl_Position = vec4(vp, 1.0);\n"
		"    fragColor = vertexColor;\n"
		"}";
	
	ShaderProgram* rectangle1_shaderProgram = new ShaderProgram();
	Rectangle* rectangle1 = new Rectangle(rectangleVertices, sizeof(rectangleVertices), rectangle1_shaderProgram);
	rectangle1_shaderProgram->addShader(GL_FRAGMENT_SHADER, fragment_shader_color);
	rectangle1_shaderProgram->addShader(GL_VERTEX_SHADER, vertex_shader_color);
	rectangle1_shaderProgram->createProgram();
	this->models.push_back(rectangle1);
}