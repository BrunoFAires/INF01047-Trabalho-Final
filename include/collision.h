#include <string>

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
};

#endif

bool hitboxesCollide(const Hitbox& hitbox1, const Hitbox& hitbox2);
