#ifndef CAMERA_H
#define CAMERA_H

#include <glm/glm.hpp>  // GLM: OpenGL Mathematics
#include <glm/gtc/matrix_transform.hpp> // GLM matrix transformations
#include <glm/gtc/type_ptr.hpp> // GLM type conversions
#include "glad/glad.h"
#include "GLFW/glfw3.h"

class Camera {
public:
    // Camera variables
    glm::vec2 pos{};
    glm::vec2 screen_size{};
    float zoom = 1.0f;

public:
    /**
     * \brief Camera
     * \param screen_size screen_size `glm::vec2`
     * \param pos pos `glm::vec2`
     */
    explicit Camera(glm::vec2 screen_size, glm::vec2 pos);

    void update(glm::vec2 window_size) const;


};



#endif //CAMERA_H
