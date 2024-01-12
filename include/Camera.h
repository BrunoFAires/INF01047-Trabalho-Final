#include "glm/mat4x4.hpp"

class Camera
{
private:
    float g_CameraTheta = 0.0f;                       // Ângulo no plano ZX em relação ao eixo Z
    float g_CameraPhi = 0.0f;                         // Ângulo em relação ao eixo Y
    float g_CameraDistance = 30.5f;                   // Distância da câmera para a origem
    float g_CurrentCameraDistance = g_CameraDistance; // Distância da câmera para a origem
    glm::vec4 positionVector = glm::vec4(0, 0, 0, 1.0f);
    glm::vec4 viewVector = glm::vec4(0.0f, 0.0f, 0.0f, 0.0f);
    glm::vec4 upVector = glm::vec4(0.0f, 1.0f, 0.0f, 0.0f);
    float velocity = 0.02;

public:
    Camera(float theta, float phi, float distance, float x, float y, float z);
    float getCameraTheta();
    float getCameraPhi();
    float getCameraDistance();
    glm::vec4 getPositionVector();
    glm::vec4 getViewVector();
    glm::vec4 getUpVector();

    void setCameraTheta(float value);
    void setCameraPhi(float value);
    void setCameraDistance(float value);
    void setPosition(float x, float y, float z);
    void moveForward();
    void moveBackwar();
    void moveLeft();
    void moveRight();
    void updateView();
    void updatePosition();
    void restart();
};

Camera::Camera(float theta, float phi, float distance, float x, float y, float z)
{
    g_CameraTheta = theta;
    g_CameraPhi = phi;
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
    positionVector.x += velocity * viewVector.x;
    positionVector.y += velocity * viewVector.y;
    positionVector.z += velocity * viewVector.z;
}

void Camera::moveBackwar()
{
    positionVector.x -= velocity * viewVector.x;
    positionVector.y -= velocity * viewVector.y;
    positionVector.z -= velocity * viewVector.z;
}

void Camera::moveLeft()
{
    glm::vec4 cameraAux = Matrix_Rotate_Y(1.5708) * viewVector;
    positionVector.x += velocity * cameraAux.x;
    positionVector.z += velocity * cameraAux.z;
}

void Camera::moveRight()
{
    glm::vec4 cameraAux = Matrix_Rotate_Y(1.5708) * viewVector;
    positionVector.x -= velocity * cameraAux.x;
    positionVector.z -= velocity * cameraAux.z;
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
    float y = r * sin(g_CameraPhi);
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