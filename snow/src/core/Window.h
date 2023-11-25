#ifndef SNOW_WINDOW_H
#define SNOW_WINDOW_H

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "../math/Vector2.h"

class Window {
public:

    Window();

    Window(const char* title, Vector2 screen_size);

    void resize_window();

    GLFWwindow* glfw_window = nullptr;
protected:
    Vector2 screen_size;
};


#endif //SNOW_WINDOW_H
