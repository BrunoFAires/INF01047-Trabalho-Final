#ifndef CAMERA_H
#define CAMERA_H

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

#endif // CAMERA_H