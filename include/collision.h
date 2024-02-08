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

struct SphereObject
{
    float radius, x, y, z;

    glm::mat4 getModelMatrix()
    {
        glm::mat4 model = Matrix_Identity();
        model = model * Matrix_Translate(x, y, z);
        model = model * Matrix_Scale(radius, radius, radius);
        return model;
    }
};

struct RectangularObject
{
    float width, height, depth, x, y, z;
    int rotation;

    glm::mat4 getModelMatrix()
    {
        glm::mat4 model = Matrix_Identity();
        model = model * Matrix_Translate(x, y, z);
        model = model * Matrix_Rotate_Y((M_PI) / 180 * rotation);
        model = model * Matrix_Scale(width, height, depth);
        return model;
    }

    void move(DIRECTION direction, float qty = 1.0f)
    {
        switch (direction)
        {
        case FORWARD:
            z -= 1;
            break;
        case BACKWARD:
            z += 1;
            break;
        case LEFT:
            x -= 1;
            break;
        case RIGHT:
            x += 1;
            break;
        }
    }

    glm::vec3 getCenterPoint()
    {
        return getModelMatrix()[3];
    }

    RectangularObject clone()
    {
        return {
            .width = width,
            .height = height,
            .depth = depth,
            .x = x,
            .y = y,
            .z = z,
            .rotation = rotation};
    };
};

#endif

bool testAABBCollision(RectangularObject obj1, RectangularObject obj2);
bool testeSphereCollision(glm::vec3 point, SphereObject obj2);
bool testePointPlaneCollision(glm::vec3 point, glm::vec3 movementDirection, RectangularObject obj2);
void printMatrix(const glm::mat4 &matrix);
