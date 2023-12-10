#include "MyScene.h"

void MyScene::Once() {
    std::cout << "hello once" << std::endl;
}

void MyScene::Update(double dt) {
    std::cout << "hello update" << std::endl;
}

void MyScene::Draw() {
    std::cout << "hello draw" << std::endl;
}

