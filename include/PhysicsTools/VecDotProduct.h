#pragma once
#pragma once
#include "Vec2D.h"
#include "Vec3D.h"


inline float Dot(const Vec2D& a, const Vec2D& b) { return a.x * b.x + a.y * b.y; }
inline float Dot(const Vec3D& a, const Vec3D& b) { return a.x * b.x + a.y * b.y + a.z * b.z; }
