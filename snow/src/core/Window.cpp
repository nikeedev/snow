#include "Window.h"
#include <iostream>

void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
    glViewport(0, 0, width, height);
}

Window::Window(const char *title, glm::vec2 screen_size) {
    glfw_window = glfwCreateWindow(static_cast<int>(screen_size.x), static_cast<int>(screen_size.y), title, nullptr,
                                   nullptr);

    this->screen_size = screen_size;

    if (glfw_window == nullptr) {
        glfwTerminate();
        std::cerr << "ERROR CODE -1;\n\tFailed to create GLFW window" << std::endl;
    }

    glfwMakeContextCurrent(glfw_window);
    glfwSetFramebufferSizeCallback(glfw_window, framebuffer_size_callback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "ERROR CODE -1;\n\tFailed to init GLAD" << std::endl;
    }
}

Window::~Window() {
    glfwTerminate();
}

void Window::resize_window() {
    glfwGetWindowSize(glfw_window, reinterpret_cast<int *>(&screen_size.x), reinterpret_cast<int *>(&screen_size.y));
}

