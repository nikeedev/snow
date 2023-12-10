#ifndef SNOW_WINDOW_H
#define SNOW_WINDOW_H

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "glm/glm.hpp"

class Window {
public:

    Window(const char* title = "Snow", glm::vec2 screen_size = glm::vec2{900, 600});

    void resize_window();

    GLFWwindow* glfw_window = nullptr;

    ~Window();
protected:
    glm::vec2 screen_size;
};


#endif //SNOW_WINDOW_H
