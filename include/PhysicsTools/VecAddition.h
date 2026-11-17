#pragma once
#include "Vec2D.h"
#include "Vec3D.h"


inline Vec2D operator+(const Vec2D& a, const Vec2D& b) { return Vec2D{ a.x + b.x, a.y + b.y }; }
inline Vec3D operator+(const Vec3D& a, const Vec3D& b) { return Vec3D{ a.x + b.x, a.y + b.y, a.z + b.z }; }
