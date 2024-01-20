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

Hitbox Player::getHitbox()
{
    glm::vec4 pos = getCamera().getPositionVector();
    float playerWidth = 4.0f;
    return {
        .x1 = pos.x - playerWidth / 2.0f,
        .x2 = pos.x + playerWidth / 2.0f,
        .y1 = pos.y - playerWidth / 2.0f,
        .y2 = pos.y + playerWidth / 2.0f,
        .z1 = pos.z - playerWidth / 2.0f,
        .z2 = pos.z + playerWidth / 2.0f,
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

    *(newPlayer->camera) = *camera;

    return newPlayer;
}