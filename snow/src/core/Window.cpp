#include "Window.h"
#include <stdexcept>

void framebuffer_size_callback(GLFWwindow *window, int width, int height) {
    glViewport(0, 0, width, height);
}

Window::Window() {
    glfw_window = glfwCreateWindow(900, 600, "Snow", nullptr, nullptr);

    if (glfw_window == nullptr)
    {
        glfwTerminate();
        throw std::runtime_error("ERROR CODE -1;\n\tFailed to create GLFW window");
    }

    glfwMakeContextCurrent(glfw_window);
    glfwSetFramebufferSizeCallback(glfw_window, framebuffer_size_callback);
}

Window::Window(const char* title, Vector2 screen_size) {
     glfw_window = glfwCreateWindow((int)screen_size.x, (int)screen_size.y, title, nullptr, nullptr);

     if (glfw_window == nullptr)
     {
         glfwTerminate();
         throw std::runtime_error("ERROR CODE -1;\n\tFailed to create GLFW window");
     }

     glfwMakeContextCurrent(glfw_window);
     glfwSetFramebufferSizeCallback(glfw_window, framebuffer_size_callback);

     if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
     {
         throw std::runtime_error("ERROR CODE -1;\n\tFailed to init GLAD");
     }
 }


void Window::resize_window() {
    glfwGetWindowSize(glfw_window, reinterpret_cast<int *>(&screen_size.x), reinterpret_cast<int *>(&screen_size.y));
}

