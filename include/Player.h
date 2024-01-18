#ifndef PLAYER_H
#define PLAYER_H

#include "glm/mat4x4.hpp"
#include "glm/mat4x4.hpp"
#include "Camera.h"
#include "collision.h"

class Player
{
private:
    glm::vec4 positionVector = glm::vec4(0, 0, 0, 1.0f);
    float velocity = 0.02;
    Camera *camera;

public:
    Player(float x, float y, float z);
    glm::vec4 getPositionVector();
    Camera &getCamera();
    Hitbox getHitbox();

    void moveForward();
    void movebackward();
    void moveLeft();
    void moveRight();
    void restart();
};

#endif // PLAYER_H