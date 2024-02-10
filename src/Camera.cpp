#include "Camera.h"
#include "matrices.h"
#include <algorithm>

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

glm::vec3 Camera::getCenterPoint()
{
    return glm::vec3(positionVector.x, positionVector.y, positionVector.z);
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

void Camera::updateTheta(float value)
{
    g_CameraTheta = -value;
}

void Camera::setCameraPhi(float value)
{
    const float minPhi = 1.58f;

    g_CameraPhi += value;

    // Usamos isso para garantir que o Phi será maior que Pi/2, evitando que a câmera inverta
    g_CameraPhi = std::max(minPhi, g_CameraPhi);
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

void Camera::moveForward(float qty)
{
    positionVector.z -= qty;
}

void Camera::moveBackward(float qty)
{
    positionVector.z += qty;
}

void Camera::moveLeft(float qty)
{
    positionVector.x -= qty;
}

void Camera::moveRight(float qty)
{
    positionVector.x += qty;
}

void Camera::moveToViewVector(DIRECTION direction, float qty)
{
    // Como o produto vetorial produz um vetor perpendicular aos dois vetores,
    // podemos obter o vetor que aponta para a esquerda:
    glm::vec3 leftVector = glm::cross(glm::vec3(upVector), glm::vec3(viewVector));

    // Normalizamos os vetores para obter um vetor unitário na mesma direçãox'
    glm::vec3 normalizedViewVector = glm::normalize(glm::vec3(viewVector));
    glm::vec3 normalizedLeftVector = glm::normalize(leftVector);

    switch (direction)
    {
    case FORWARD:
        positionVector += glm::vec4(normalizedViewVector * qty, 0.0f);
        break;
    case BACKWARD:
        positionVector -= glm::vec4(normalizedViewVector * qty, 0.0f);
        break;
    case LEFT:
        positionVector += glm::vec4(normalizedLeftVector * qty, 0.0f);
        break;
    case RIGHT:
        positionVector -= glm::vec4(normalizedLeftVector * qty, 0.0f);
        break;
    }
}

void Camera::updatePosition()
{
    positionVector.x = -viewVector.x;
    positionVector.y = -viewVector.y;
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