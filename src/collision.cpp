#include "collision.h"

bool testCollision(RectangularObject obj1, RectangularObject obj2) {
    glm::mat4 model1 = obj1.getModelMatrix();
    glm::mat4 model2 = obj2.getModelMatrix();

    glm::vec3 position1(model1[3]);
    glm::vec3 position2(model2[3]);

    glm::vec3 halfSize1 = glm::vec3(obj1.width, obj1.height, obj1.depth) * 0.5f;
    glm::vec3 halfSize2 = glm::vec3(obj2.width, obj2.height, obj2.depth) * 0.5f;

    glm::vec3 min1 = position1 - halfSize1;
    glm::vec3 max1 = position1 + halfSize1;
    glm::vec3 min2 = position2 - halfSize2;
    glm::vec3 max2 = position2 + halfSize2;

    bool overlapX = (min1.x <= max2.x) && (max1.x >= min2.x);
    bool overlapY = true;
    bool overlapZ = (min1.z <= max2.z) && (max1.z >= min2.z);

    // if (overlapX && overlapY && overlapZ)
    // {
    //     printf("min1.x: %f <= max2.x: %f; max1.x: %f >= min2.x: %f\n", min1.x, max2.x, max1.x, min2.x);
    //     printf("min1.z: %f <= max2.z: %f; max1.z: %f >= min2.z: %f\n", min1.z, max2.z, max1.z, min2.z);
    // }

    return overlapX && overlapY && overlapZ;
}


void printMatrix(const glm::mat4& matrix) {
    for (int i = 0; i < 4; ++i) {
        printf("| %9.4f %9.4f %9.4f %9.4f |\n", 
            matrix[0][i], matrix[1][i], matrix[2][i], matrix[3][i]);
    }
}