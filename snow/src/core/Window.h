#ifndef SNOW_WINDOW_H
#define SNOW_WINDOW_H

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "glm/glm.hpp"

class Window {
public:

    Window();

    Window(const char* title, glm::vec2 screen_size);

    void resize_window();

    GLFWwindow* glfw_window = nullptr;
protected:
    glm::vec2 screen_size;
};


#endif //SNOW_WINDOW_H
