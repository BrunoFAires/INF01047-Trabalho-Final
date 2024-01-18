#include <string>
#include <cmath>
#include <algorithm>

#ifndef HITBOX_H
#define HITBOX_H

struct Hitbox
{
    float x1, x2;
    float y1, y2;
    float z1, z2;

    void print() const {
        printf(
            "Hitbox: { x1: %.2f, x2: %.2f, y1: %.2f, y2: %.2f, z1: %.2f, z2: %.2f }\n",
            x1, x2, y1, y2, z1, z2
        );
    }

    void rotate(int rotation) {
        float rad = rotation * M_PI / 180.0f;

        float centerX = (x1 + x2) / 2.0f;
        float centerZ = (z1 + z2) / 2.0f;

        float cornersX[4] = {x1, x2, x2, x1};
        float cornersZ[4] = {z1, z1, z2, z2};

        for (int i = 0; i < 4; ++i) {
            float x = cornersX[i] - centerX;
            float z = cornersZ[i] - centerZ;

            cornersX[i] = cos(rad) * x - sin(rad) * z + centerX;
            cornersZ[i] = sin(rad) * x + cos(rad) * z + centerZ;
        }

        x1 = cornersX[0];
        x2 = cornersX[0];
        z1 = cornersZ[0];
        z2 = cornersZ[0];

        // Finding the min and max X and Z
        for (int i = 1; i < 4; ++i) {
            if (cornersX[i] < x1) x1 = cornersX[i];
            if (cornersX[i] > x2) x2 = cornersX[i];
            if (cornersZ[i] < z1) z1 = cornersZ[i];
            if (cornersZ[i] > z2) z2 = cornersZ[i];
        }
    }
};

#endif

bool hitboxesCollide(const Hitbox& hitbox1, const Hitbox& hitbox2);
