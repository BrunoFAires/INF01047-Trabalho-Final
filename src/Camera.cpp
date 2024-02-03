#include "Camera.h"
#include "matrices.h"

Camera::Camera(float theta, float phi, float angle, float distance, float x, float y, float z)
{
    g_CameraTheta = theta;
    g_CameraPhi = phi;
    this->angle = angle;
    g_CameraDistance = distance;
    positionVector.x = x;
    positionVector.y = y;
    positionVector.z = z;
    updateView();
}

float Camera::getCameraTheta()
{
    return g_CameraTheta;
}

float Camera::getCameraPhi()
{
    return g_CameraPhi;
}

float Camera::getCameraDistance()
{
    return g_CameraDistance;
}

glm::vec4 Camera::getPositionVector()
{
    return positionVector;
}

glm::vec4 Camera::getViewVector()
{
    return viewVector;
}

glm::vec4 Camera::getUpVector()
{
    return upVector;
}

void Camera::setCameraTheta(float value)
{
    g_CameraTheta -= value;
}

void Camera::setCameraPhi(float value)
{
    g_CameraPhi += value;
}

void Camera::setCameraDistance(float value)
{
    g_CameraDistance += value;
    updateView();
}

void Camera::setPosition(float x, float y, float z)
{
    positionVector = glm::vec4(x, y, z, 1.0f);
}

void Camera::moveForward()
{
    positionVector.z -= 0.5;
}

void Camera::moveBackward()
{
    positionVector.z += 0.5;
}

void Camera::moveLeft()
{
    positionVector.x -= 0.5;
}

void Camera::moveRight()
{
    positionVector.x += 0.5;
}

void Camera::updatePosition()
{
    positionVector.x = -viewVector.x;
    positionVector.y = -2;
    positionVector.z = -viewVector.z;
}

void Camera::updateView()
{
    float r = g_CameraDistance;
    float y = r * sin(g_CameraPhi - angle);
    float z = r * cos(g_CameraPhi) * cos(g_CameraTheta);
    float x = r * cos(g_CameraPhi) * sin(g_CameraTheta);

    viewVector.x = -x;
    viewVector.y = -y;
    viewVector.z = -z;
}

void Camera::restart()
{
    g_CameraTheta = 0.0f;
    g_CameraPhi = 0.0f;
    g_CameraDistance = 30.5f;

    positionVector.x = 16.5f;
    positionVector.z = 30.5f;
    updateView();
}