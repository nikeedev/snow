#include "Application.h"

Application::Application(const char* title, glm::vec2 _screen_size, glm::vec2 _camera_pos, const glm::vec4& _background_color) {
    this->window = Window(title, _screen_size);
    this->camera = Camera(_screen_size, _camera_pos);

    this->background_color = _background_color;
}

void Application::processInput() const {
    if (glfwGetKey(window.glfw_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window.glfw_window, true);
}

void Application::SetWindowTitle(const char* title) const {
    glfwSetWindowTitle(this->window.glfw_window, title);
}

void Application::loop() {
    double currentFrame = glfwGetTime();
    double lastFrame = currentFrame;
    double deltaTime;

    for (auto&& scene : scenes) {
        scene->Once();
    }

    while (!glfwWindowShouldClose(window.glfw_window))
    {
        currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        // Input stuff here:
        processInput();

        this->scenes[current_scene]->Update(deltaTime);

        // Rendering stuff here:
        glClearColor(0.39f, 0.58f, 0.92f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);


        // THE TRIANGLE!!!

        shaders[current_shader]->use();
        this->scenes[current_scene]->Draw();

//        glBindVertexArray(VAO);

//        glDrawArrays(GL_TRIANGLES, 0, 3);

//        glBindVertexArray(0);


        // Update stuff here:
        glfwSwapBuffers(window.glfw_window);
        glfwPollEvents();
    }
}

Application::~Application() {
    glDeleteProgram(shaders[current_shader]->ID);

    glfwTerminate();
}

