#pragma once
#include <cmath>
#include "Vec3D.h"
#include "Vec2D.h"

inline float Length(const Vec2D& v) { return std::sqrt(v.x * v.x + v.y * v.y); }
inline float Length(const Vec3D& v) { return std::sqrt(v.x * v.x + v.y * v.y + v.z * v.z); }