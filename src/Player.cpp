#include "Player.h"

Player::Player(float x, float y, float z)
{
    positionVector.x = x;
    positionVector.y = y;
    positionVector.z = z;
    camera = new Camera(0.0f, 0.0f, 10.5f, x, y, z);
}

Camera &Player::getCamera()
{
    return *camera;
}

Hitbox Player::getHitbox() {
    return {
        .x1 = positionVector.x - 0.5f, .x2 = positionVector.x + 0.5f,
        .y1 = positionVector.y - 0.5f, .y2 = positionVector.y + 0.5f,
        .z1 = positionVector.z - 0.5f, .z2 = positionVector.z + 0.5f,
    };
}


void Player::moveForward()
{
    camera->moveForward();
    positionVector.x += velocity * positionVector.x;
}

void Player::movebackward()
{
    camera->movebackward();
    positionVector.x -= velocity * positionVector.x;
}

void Player::moveLeft()
{
    camera->moveLeft();
    positionVector.z += velocity * positionVector.z;
}

void Player::moveRight()
{
    camera->moveRight();
    positionVector.z -= velocity * positionVector.z;
}

void Player::restart()
{
    camera->restart();
}