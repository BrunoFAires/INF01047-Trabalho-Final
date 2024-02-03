#include "Player.h"

Player::Player(float x, float y, float z, DIRECTION d)
{
    direction = d;
    positionVector.x = x;
    positionVector.y = y;
    positionVector.z = z;
    camera = new Camera(0.0f, -1.14f, -15, 4, x, 15, z);
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
        .rotation = rotation};
}

void Player::moveForward()
{
    if (direction == FORWARD)
    {
        camera->moveForward();
        positionVector.z -= 0.5;
    }
    else if (direction == LEFT)
    {
        camera->moveLeft();
        positionVector.x -= 0.5;
    }
    else if (direction == RIGHT)
    {
        camera->moveRight();
        positionVector.x += 0.5;
    }
    else if (direction == BACKWARD)
    {
        camera->moveBackward();
        positionVector.z += 0.5;
    }
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

void Player::rotateLeft()
{
    if (direction == FORWARD)
    {
        direction = LEFT;
    }
    else if (direction == LEFT)
    {
        direction = BACKWARD;
    }
    else if (direction == BACKWARD)
    {
        direction = RIGHT;
    }
    else
    {
        direction = FORWARD;
    }
}

void Player::rotateRight()
{

    if (direction == FORWARD)
    {
        direction = RIGHT;
    }
    else if (direction == LEFT)
    {
        direction = FORWARD;
    }
    else if (direction == BACKWARD)
    {
        direction = LEFT;
    }
    else
    {
        direction = BACKWARD;
    }
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
    Player *newPlayer = new Player(positionVector.x, positionVector.y, positionVector.z, direction);
    newPlayer->camera = new Camera(0.0f, 0.0f, 5, 4, camera->getPositionVector().x, camera->getPositionVector().y, camera->getPositionVector().z);
    return newPlayer;
}

DIRECTION Player::getDirection()
{
    return direction;
}

void Player::setRotation(float value)
{
    rotation += value;
}