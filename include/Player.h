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
    float rotation = 0;
    Camera *camera;
    DIRECTION direction = FORWARD;

public:
    Player(float x, float y, float z);
    glm::vec4 getPositionVector();
    Camera &getCamera();

    void moveForward();
    void moveBackward();
    void moveLeft();
    void moveRight();
    void restart();
    void rotateLeft();
    void rotateRight();
    Player *clone();
    void setPositionVector(glm::vec4 vector);
    RectangularObject asRectangularObject();
    DIRECTION getDirection();
};

#endif // PLAYER_H