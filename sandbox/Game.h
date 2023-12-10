#include <snow.hpp>

#ifndef SNOW_GAME_H
#define SNOW_GAME_H


class Game : public Application {
public:
    Game() : Application("Snow engine", glm::vec2(800, 600), glm::vec2(0, 0)) {};

};


#endif //SNOW_GAME_H
