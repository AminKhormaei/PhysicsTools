#pragma once
#include "Vec2D.h"
#include "Vec3D.h"


inline float Cross(const Vec2D& a, const Vec2D& b) { return a.x * b.y - a.y * b.x; }


inline Vec3D Cross(const Vec3D& a, const Vec3D& b)
{
    return Vec3D{
        a.y * b.z - a.z * b.y,  // مؤلفه‌ی x
        a.z * b.x - a.x * b.z,  // مؤلفه‌ی y
        a.x * b.y - a.y * b.x   // مؤلفه‌ی z
    };
}
