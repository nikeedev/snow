#include "Application.h"

Application::Application(const char* title, Vector2 screen_size) {
    this->window = Window(title, screen_size);
}

void Application::processInput() {
    if (glfwGetKey(window.glfw_window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window.glfw_window, true);
}
