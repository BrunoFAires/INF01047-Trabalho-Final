#include <string>
#include <cmath>
#include <algorithm>
#include <glm/mat4x4.hpp>
#include <glm/vec4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "matrices.h"

#ifndef HITBOX_H
#define HITBOX_H

enum DIRECTION
{
    FORWARD,
    BACKWARD,
    LEFT,
    RIGHT
};

struct RectangularObject
{
    float width, height, depth, x, y, z;
    int rotation;

    glm::mat4 getModelMatrix()
    {
        glm::mat4 model = Matrix_Identity();
        model = model * Matrix_Translate(x, y, z);
        // model = model * Matrix_Rotate_Y((M_PI) / 180 * rotation);
        model = model * Matrix_Scale(width, height, depth);
        return model;
    }

    void move(DIRECTION direction, glm::vec4 viewVector, float qty = 1.0f)
    {
        float velocity = 1.0f;
        glm::vec4 cameraAux = Matrix_Rotate_Y(1.5708) * viewVector;

        switch (direction)
        {
        case FORWARD:
            x += velocity * viewVector.x;
            z += velocity * viewVector.z;
            break;
        case BACKWARD:
            x -= velocity * viewVector.x;
            z -= velocity * viewVector.z;
            break;
        case LEFT:
            x += velocity * cameraAux.x;
            z += velocity * cameraAux.z;
            break;
        case RIGHT:
            x -= velocity * cameraAux.x;
            z -= velocity * cameraAux.z;
            break;
        }
    }
};

#endif

bool testCollision(RectangularObject obj1, RectangularObject obj2);
void printMatrix(const glm::mat4& matrix);
