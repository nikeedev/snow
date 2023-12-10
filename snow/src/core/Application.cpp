#include "Application.h"


Application::Application(const char* title, glm::vec2 _screen_size, glm::vec2 _camera_pos) {
    this->window = Window(title, _screen_size);
    this->camera = Camera(_screen_size, _camera_pos);

    scenes.reserve(MAX_SCENES);
}

Application::Application() : Application("Snow engine", glm::vec2{900, 600}, glm::vec2 {}) {}

void Application::processInput() const {
    if (glfwGetKey(window.glfw_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window.glfw_window, true);
}

void Application::SetWindowTitle(const char* title) const {
    glfwSetWindowTitle(this->window.glfw_window, title);
}

void Application::loop() {

    for (auto&& scene : scenes) {
        if (scene == nullptr) {
            std::cerr << "No scene initialized! Use `app.addScene(\"scene\");`" << std::endl;
            exit(-1);
        }
    }

    double currentFrame = glfwGetTime();
    double lastFrame = currentFrame;
    double deltaTime;

    for (auto&& scene : scenes) {
        scene->Once();
    }

    int i = 0;

    while (!glfwWindowShouldClose(window.glfw_window))
    {
        currentFrame = glfwGetTime();
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

        // Input stuff here:
        processInput();

        if (scenes[current_scene] != nullptr) {

            this->scenes[current_scene]->Update(deltaTime);

            std::cout << "R" << this->scenes[current_scene]->background_color.r << " G" << this->scenes[current_scene]->background_color.g << " B" << this->scenes[current_scene]->background_color.b << " A" << this->scenes[current_scene]->background_color.a << std::endl;
            // Rendering stuff here:
            glClearColor((GLfloat)this->scenes[current_scene]->background_color.r, (GLfloat)this->scenes[current_scene]->background_color.g, (GLfloat)this->scenes[current_scene]->background_color.b, (GLfloat)this->scenes[current_scene]->background_color.a);
            glClear(GL_COLOR_BUFFER_BIT);

            // THE TRIANGLE!!!

            shaders[current_shader].use();
            this->scenes[current_scene]->Draw();

    //        glBindVertexArray(VAO);

    //        glDrawArrays(GL_TRIANGLES, 0, 3);

    //        glBindVertexArray(0);


            // Update stuff here:
            glfwSwapBuffers(window.glfw_window);
            glfwPollEvents();

            std::cout << "Iteration: " << i++ << std::endl;

        } else {
            std::cerr << "ERROR: Scenes are not initialized! (Why?)" << std::endl;
            exit(-1);
        }
    }
}

void Application::addScene(std::unique_ptr<Scene> scene) {
    this->scenes.push_back(std::move(scene));
}

Application::~Application() {
    glDeleteProgram(shaders[current_shader].ID);
}

