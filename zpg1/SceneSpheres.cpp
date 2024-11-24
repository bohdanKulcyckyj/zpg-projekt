#include "SceneSpheres.h"

SceneSpheres::SceneSpheres(GLFWwindow* w) : Scene(w) {
}

void SceneSpheres::init() {
    // Light setup
    Light* light = new Light(glm::vec3(0.0f, 0.0f, -0.6f), glm::vec4(1.0, 1.0, 1.0, 1.0));

    // Sphere at the top center
    ShaderProgram* sphereTop_shaderProgram = new ShaderProgram(camera);
    sphereTop_shaderProgram->addLight(light);
    sphereTop_shaderProgram->loadShader("VertexShaderPhong.glsl", "FragmentShaderPhong.glsl");
    SphereModel* sphereTop_model = new SphereModel();
    DrawableObject* sphereTop_obj = new DrawableObject(sphereTop_shaderProgram, sphereTop_model);
    sphereTop_obj->addTransform(new TransformTranslate(glm::vec3(0.0f, 2.0f, 0.0f)));  // Position at top center
    this->objects.push_back(sphereTop_obj);

    // Sphere at the bottom center
    ShaderProgram* sphereBottom_shaderProgram = new ShaderProgram(camera);
    sphereBottom_shaderProgram->addLight(light);
    sphereBottom_shaderProgram->loadShader("VertexShaderPhong.glsl", "FragmentShaderPhong.glsl");
    SphereModel* sphereBottom_model = new SphereModel();
    DrawableObject* sphereBottom_obj = new DrawableObject(sphereBottom_shaderProgram, sphereBottom_model);
    sphereBottom_obj->addTransform(new TransformTranslate(glm::vec3(0.0f, -2.0f, 0.0f)));  // Position at bottom center
    this->objects.push_back(sphereBottom_obj);

    // Sphere on the left side
    ShaderProgram* sphereLeft_shaderProgram = new ShaderProgram(camera);
    sphereLeft_shaderProgram->addLight(light);
    sphereLeft_shaderProgram->loadShader("VertexShaderPhong.glsl", "FragmentShaderPhong.glsl");
    SphereModel* sphereLeft_model = new SphereModel();
    DrawableObject* sphereLeft_obj = new DrawableObject(sphereLeft_shaderProgram, sphereLeft_model);
    sphereLeft_obj->addTransform(new TransformTranslate(glm::vec3(-2.0f, 0.0f, 0.0f)));  // Position at left side
    this->objects.push_back(sphereLeft_obj);

    // Sphere on the right side
    ShaderProgram* sphereRight_shaderProgram = new ShaderProgram(camera);
    sphereRight_shaderProgram->addLight(light);
    sphereRight_shaderProgram->loadShader("VertexShaderPhong.glsl", "FragmentShaderPhong.glsl");
    SphereModel* sphereRight_model = new SphereModel();
    DrawableObject* sphereRight_obj = new DrawableObject(sphereRight_shaderProgram, sphereRight_model);
    sphereRight_obj->addTransform(new TransformTranslate(glm::vec3(2.0f, 0.0f, 0.0f)));  // Position at right side
    this->objects.push_back(sphereRight_obj);

    // Attach the shader programs to the camera (if necessary for updates)
    this->camera->attach(sphereTop_shaderProgram);
    this->camera->attach(sphereBottom_shaderProgram);
    this->camera->attach(sphereLeft_shaderProgram);
    this->camera->attach(sphereRight_shaderProgram);
}
