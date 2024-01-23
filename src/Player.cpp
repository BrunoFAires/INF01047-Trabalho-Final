#include "Player.h"

Player::Player(float x, float y, float z)
{
    positionVector.x = x;
    positionVector.y = y;
    positionVector.z = z;
    camera = new Camera(0.0f, 0.0f, 5, 4, x, 5, z);
}

Camera &Player::getCamera()
{
    return *camera;
}

RectangularObject Player::asRectangularObject()
{
    float player_size = 3.5f;
    return {
        .width = player_size,
        .height = player_size,
        .depth = player_size,
        .x = positionVector.x,
        .y = -2.0f,
        .z = positionVector.z,
        .rotation = 0
    };
}

void Player::moveForward()
{
    camera->moveForward();
    positionVector.x = camera->getPositionVector().x;
    positionVector.z = camera->getPositionVector().z;
}

void Player::moveBackward()
{
    camera->moveBackward();
    positionVector.x = camera->getPositionVector().x;

    positionVector.z = camera->getPositionVector().z;
}

void Player::moveLeft()
{
    camera->moveLeft();
    positionVector.x = camera->getPositionVector().x;

    positionVector.z = camera->getPositionVector().z;
}

void Player::moveRight()
{
    camera->moveRight();
    positionVector.x = camera->getPositionVector().x;

    positionVector.z = camera->getPositionVector().z;
}

glm::vec4 Player::getPositionVector()
{
    return positionVector;
}

void Player::restart()
{
    camera->restart();
}

Player *Player::clone()
{
    Player *newPlayer = new Player(positionVector.x, positionVector.y, positionVector.z);
    newPlayer->camera = new Camera(0.0f, 0.0f, 5, 4, camera->getPositionVector().x, camera->getPositionVector().y, camera->getPositionVector().z);
    return newPlayer;
}