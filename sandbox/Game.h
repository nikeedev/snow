#include <snow.hpp>

#ifndef GAME_H
#define GAME_H


class Game : public Application {
public:
    Game() : Application("Sandbox", glm::vec2(900, 600), glm::vec2(0, 0)) {
        std::cout << "from game class" << std::endl;
    };

};


#endif //GAME_H
