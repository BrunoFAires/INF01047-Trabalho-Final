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

void Player::moveForward()
{
    camera->moveForward();
    positionVector.x += velocity * positionVector.x;
}

void Player::moveBackwar()
{
    camera->moveBackwar();
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