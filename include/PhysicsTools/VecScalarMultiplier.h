#pragma once
#include "Vec2D.h"
#include "Vec3D.h"

inline Vec2D operator*(float s, const Vec2D& v) { return Vec2D{ s * v.x, s * v.y }; }
inline Vec2D operator*(const Vec2D& v, float s) { return Vec2D{ v.x * s, v.y * s }; }

inline Vec3D operator*(float s, const Vec3D& v) { return Vec3D{ s * v.x, s * v.y, s * v.z }; }
inline Vec3D operator*(const Vec3D& v, float s) { return Vec3D{ v.x * s, v.y * s, v.z * s }; }