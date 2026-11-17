// VecScalarDivider.h
#pragma once
#include <cassert>
#include "Vec2D.h"
#include "Vec3D.h"
#include "VecScalarMultiplier.h"

// v / k is computed as v * (1/k): one reciprocal for every component.
//
// The zero check stays an assert instead of a runtime branch. On the hot path
// a predictable branch still costs a compare plus a jump per component, and
// the assert already documents the precondition. `operator/=` lives on the
// vector classes, where it mutates in place without building a temporary.
inline Vec2D operator/(const Vec2D& v, float k)
{
    assert(k != 0.0f && "Vec2D division by zero");
    return v * (1.0f / k);
}

inline Vec3D operator/(const Vec3D& v, float k)
{
    assert(k != 0.0f && "Vec3D division by zero");
    return v * (1.0f / k);
}
