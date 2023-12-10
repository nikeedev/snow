//#include <iostream>
#include "Game.h"
#include "MyScene.h"
#include <memory>

int main()
{
    Game app;

    app.addScene(std::make_unique<MyScene>());
    
    app.loop();
}

