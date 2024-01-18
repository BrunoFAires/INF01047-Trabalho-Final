#include "collision.h"

bool hitboxesCollide(const Hitbox& hitbox1, const Hitbox& hitbox2) {
    bool xOverlap = (hitbox1.x1 <= hitbox2.x2 && hitbox1.x2 >= hitbox2.x1);

    // Temporarily ignoring Y overlap
    // bool yOverlap = (hitbox1.y1 <= hitbox2.y2 && hitbox1.y2 >= hitbox2.y1);

    bool zOverlap = (hitbox1.z1 <= hitbox2.z2 && hitbox1.z2 >= hitbox2.z1);

    bool didCollide = xOverlap && zOverlap;
    
    return didCollide;
}
