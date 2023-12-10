//#include <iostream>
#include "Game.h"
#include "MyScene.h"
#include <memory>

int main()
{
    Game app;

    app.addShader(Shader("shaders/shader.vert", "shaders/shader.frag"));

    app.addScene(std::make_unique<MyScene>());

    app.loop();
}

