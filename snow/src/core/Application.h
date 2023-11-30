#ifndef SNOW_APPLICATION_H
#define SNOW_APPLICATION_H

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "glm/glm.hpp"
#include "Window.h"
#include "Camera.h"
#include "Scene.h"
#include "Shader.h"
#include <vector>
#include <memory>

class Application {

public:

    /**
     * \brief Application class, sets up all from window, camera and game loop.
     * \param title Window title
     * \param screen_size Sets the window size for the inital window `glm::vec2`.
     * \param _background_color Sets the color using the `glm::vec4` format
     */
    Application(const char* title, glm::vec2 screen_size, const glm::vec4& _background_color);

    /**
     * \brief Gameloop for your Snow application:
     * \param SnowInit Pass an init function which will be ran once before the gameloop. Put your "static" game code in here, which will be run once.
     * \param SnowUpdate Pass an update function which will be ran in the gameloop. Put your "dynamic" game code in here
     *
    **/
    void loop();

    void Application::SetWindowTitle(const char* title) const;

private:
    Window window;

    int current_scene = 0;
    std::vector<std::unique_ptr<Scene>> scenes;

    int current_shader = 0;
    std::vector<Shader> shaders;

    Camera camera;

    glm::vec4 background_color{};
    void processInput() const;

    ~Application();

};


#endif //SNOW_APPLICATION_H
