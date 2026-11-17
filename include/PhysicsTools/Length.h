#pragma once
#include <cmath>
#include "Vec3D.h"
#include "Vec2D.h"

// LengthSquared is the primitive: it is branch-free, needs no sqrt, and is the
// right thing to compare against a radius when doing broad-phase/distance
// rejection (Length(a - b) < r  =>  LengthSquared(a - b) < r*r). Only take the
// sqrt when you actually need the magnitude.
inline float LengthSquared(const Vec2D& v) { return v.x * v.x + v.y * v.y; }
inline float LengthSquared(const Vec3D& v) { return v.x * v.x + v.y * v.y + v.z * v.z; }

// These go through LengthSquared so the square is computed once and shared.
inline float Length(const Vec2D& v) { return std::sqrt(LengthSquared(v)); }
inline float Length(const Vec3D& v) { return std::sqrt(LengthSquared(v)); }

// 1 / length, returning 0 for a zero vector so callers never divide by zero
// and never need their own check.
inline float InvLength(const Vec2D& v)
{
    const float lenSq = LengthSquared(v);
    return lenSq > 0.0f ? 1.0f / std::sqrt(lenSq) : 0.0f;
}

inline float InvLength(const Vec3D& v)
{
    const float lenSq = LengthSquared(v);
    return lenSq > 0.0f ? 1.0f / std::sqrt(lenSq) : 0.0f;
}

// In place normalize: no temporary, no vector return, so the caller's storage
// is reused and the compiler can keep the values in registers.
inline void Normalize(Vec2D& v)
{
    const float inv = InvLength(v);
    v.x *= inv;
    v.y *= inv;
}

inline void Normalize(Vec3D& v)
{
    const float inv = InvLength(v);
    v.x *= inv;
    v.y *= inv;
    v.z *= inv;
}

inline Vec2D Normalized(const Vec2D& v) { Vec2D out = v; Normalize(out); return out; }
inline Vec3D Normalized(const Vec3D& v) { Vec3D out = v; Normalize(out); return out; }
