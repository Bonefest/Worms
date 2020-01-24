#include "MiscMath.h"

#include <cmath>

float toRad(float deg) {
    return M_PI * (deg / 180.0f);
}

float toDeg(float rad) {
    return (rad * 180.0f) / M_PI;
}
