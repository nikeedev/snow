#ifndef SNOW_SCENE_H
#define SNOW_SCENE_H

#include "glm/glm.hpp"

class Scene
{
public:

    virtual void Once() = 0;
    virtual void Update(double dt) = 0;
    virtual void Draw() = 0;
    glm::vec4 background_color{};

    virtual ~Scene() {}
};

#endif //SNOW_SCENE_H
