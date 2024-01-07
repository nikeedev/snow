#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "glm/glm.hpp"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <vector>

class Rectangle {
public:
    Rectangle(glm::vec3 pos, glm::vec2 size, glm::vec4 color);
private:
    unsigned int VAO, VBO;
};



#endif //RECTANGLE_H
