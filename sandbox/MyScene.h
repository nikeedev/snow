#include <snow.hpp>

#ifndef SNOW_MYSCENE_H
#define SNOW_MYSCENE_H


class MyScene : public Scene {
public:
    MyScene() {
        this->background_color = glm::vec4{0.39f, 0.6f, 1.0f, 1.0f};
    }

    void Once() override;

    void Update(double dt) override;

    void Draw() override;

};


#endif //SNOW_MYSCENE_H
