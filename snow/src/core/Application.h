#ifndef SNOW_APPLICATION_H
#define SNOW_APPLICATION_H

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "Window.h"
#include "../math/Vector2.h"
#include <vector>

class Application {

public:

    Application(const char* title, Vector2 screen_size);

private:
    Window window;

    void processInput() const;

//    std::vector<Shader> shaders;
};


#endif //SNOW_APPLICATION_H
