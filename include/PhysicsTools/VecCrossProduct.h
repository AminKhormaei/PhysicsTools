#pragma once
#include "Vec2D.h"
#include "Vec3D.h"
/**
 * @file Cross.h
 * @brief Cross product helpers for Vec2D and Vec3D.
 *
 * @details
 * The 2D cross product returns a scalar: the z component of the 3D cross
 * product of the two vectors placed in the XY plane. Its sign tells the
 * orientation: positive if `b` is counter-clockwise from `a`, negative if
 * clockwise, zero if they are parallel.
 *
 * The 3D cross product returns a vector perpendicular to both inputs.
 * Its length equals the area of the parallelogram they span.
 *
 * Neither function modifies its arguments.
 *
 * @par Example
 * @code{.cpp}
 * float  area2 = Cross(Vec2D(1, 0), Vec2D(0, 1));          // 1
 * Vec3D  n     = Cross(Vec3D(1, 0, 0), Vec3D(0, 1, 0));   // (0, 0, 1)
 * @endcode
 */

/**
 * @brief 2D cross product (scalar z component of the 3D cross product).
 * @param a The left-hand vector. Not modified.
 * @param b The right-hand vector. Not modified.
 * @return `a.x * b.y - a.y * b.x`.
 *
 * @details
 * - Result > 0: `b` is counter-clockwise from `a`.
 * - Result < 0: `b` is clockwise from `a`.
 * - Result == 0: `a` and `b` are parallel (or one of them is zero).
 * - The absolute value is the area of the parallelogram spanned by `a` and `b`.
 *
 * @code{.cpp}
 * float s = Cross(Vec2D(1.0f, 0.0f), Vec2D(0.0f, 1.0f));   // s == 1
 * @endcode
 */

inline float Cross(const Vec2D& a, const Vec2D& b) { return a.x * b.y - a.y * b.x; }


inline Vec3D Cross(const Vec3D& a, const Vec3D& b)
{
    return Vec3D{
        a.y * b.z - a.z * b.y,
        a.z * b.x - a.x * b.z,
        a.x * b.y - a.y * b.x
    };
}
