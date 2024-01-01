#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "glm/glm.hpp"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <vector>

class Triangle {
public:
    Triangle(glm::vec3 pos, glm::vec2 size, glm::vec4 color);

    Triangle(const Triangle&) = delete;

    void render() const;

private:
    unsigned int VAO = 0, VBO = 0;
};



#endif //TRIANGLE_H
