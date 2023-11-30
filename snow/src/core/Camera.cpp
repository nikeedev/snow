#include "Camera.h"

/**
     * \brief Camera
     * \param screen_size screen_size `glm::vec2`
     * \param pos pos `glm::vec2`
     *
 */
Camera::Camera(glm::vec2 screen_size, glm::vec2 pos) {
    this->pos = pos;
    this->screen_size = screen_size;
}

void Camera::update(glm::vec2 window_size) const {
    // Update view matrix based on camera position and zoom
    glm::mat4 viewMatrix = glm::ortho(pos.x, window_size.x * zoom + pos.x, window_size.y * zoom + pos.y, pos.y, -1.0f,
                                      1.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadMatrixf(glm::value_ptr(viewMatrix));
}
