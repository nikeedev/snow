#include <snow.hpp>
#include "glm/glm.hpp"

#ifndef MYSCENE_H
#define MYSCENE_H


class MyScene : public Scene {
public:
    MyScene() {
        this->background_color = glm::vec4{0.39f, 0.6f, 1.0f, 1.0f};
    }

    Triangle triangle = Triangle(glm::vec3(), glm::vec2(), glm::vec4());

    void Once() override {

    }

    void Update(double dt) override  {

    }

    void Draw() override {

        triangle.render();
    }


};


#endif //MYSCENE_H
