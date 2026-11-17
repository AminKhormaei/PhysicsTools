// Perpendicular.h
#pragma once
#include "Vec2D.h"
#include "Vec3D.h"
#include "VecCrossProduct.h"

/**
 * @file Perpendicular.h
 * @brief Functions that return a vector perpendicular to a given vector.
 *
 * @details
 * - In 2D, the perpendicular of a vector is unique up to sign. This header
 *   returns the counter-clockwise rotation by 90 degrees.
 * - In 3D, infinitely many vectors are perpendicular to a given vector.
 *   Perpendicular() returns one deterministic choice, built from a cross
 *   product with the coordinate axis least aligned with the input.
 *
 * The results are not normalized. Call Normalize() or use Normalized()
 * from Length.h if you need a unit vector.
 *
 * None of these functions modify their input.
 *
 * @par Example
 * @code{.cpp}
 * Vec2D p2 = Perpendicular(Vec2D(1.0f, 0.0f));          // (0, 1)
 * Vec3D p3 = Perpendicular(Vec3D(1.0f, 0.0f, 0.0f));    // (0, 0, 1)
 * float d  = Dot(Vec2D(1.0f, 0.0f), p2);                // 0, so they are perpendicular
 * @endcode
 */

/**
 * @brief Returns the 2D vector rotated 90 degrees counter-clockwise.
 * @param v The input vector. Not modified.
 * @return A new vector `(-v.y, v.x)`.
 *
 * @details
 * - The result has the same length as `v`.
 * - `Dot(v, Perpendicular(v))` is always zero.
 * - Rotating twice gives the negated input: `Perpendicular(Perpendicular(v)) == -v`.
 * - The zero vector maps to the zero vector.
 *
 * @code{.cpp}
 * Vec2D p = Perpendicular(Vec2D(3.0f, 4.0f));   // (-4, 3)
 * @endcode
 *
 * @see Dot(const Vec2D&, const Vec2D&)
 */
inline Vec2D Perpendicular(const Vec2D& v)
{
    return Vec2D{ -v.y, v.x };
}

/**
 * @brief Returns a vector perpendicular to a 3D vector.
 * @param v The input vector. Not modified.
 * @return A new vector `v x a`, where `a` is the coordinate axis (X, Y, or Z)
 *         whose absolute component in `v` is the smallest. The result is
 *         perpendicular to `v`, but not unique.
 *
 * @details
 * - Choosing the axis least aligned with `v` avoids a near-zero cross product,
 *   so the result stays numerically well-conditioned for any non-zero input.
 * - The result is zero only if `v` is the zero vector.
 * - The result is not normalized. Its length is `Length(v) * sin(theta)`,
 *   where `theta` is the angle between `v` and the chosen axis.
 * - The same input always gives the same output (deterministic).
 *
 * @code{.cpp}
 * Vec3D p = Perpendicular(Vec3D(1.0f, 0.0f, 0.0f));   // (0, 0, 1)
 * float d = Dot(Vec3D(1.0f, 0.0f, 0.0f), p);          // 0
 * @endcode
 *
 * @see Cross(const Vec3D&, const Vec3D&)
 */
inline Vec3D Perpendicular(const Vec3D& v)
{
    const float ax = v.x < 0.0f ? -v.x : v.x;
    const float ay = v.y < 0.0f ? -v.y : v.y;
    const float az = v.z < 0.0f ? -v.z : v.z;

    // Pick the axis whose absolute component in v is smallest.
    Vec3D axis;
    if (ax <= ay && ax <= az)
        axis = Vec3D{ 1.0f, 0.0f, 0.0f };
    else if (ay <= az)
        axis = Vec3D{ 0.0f, 1.0f, 0.0f };
    else
        axis = Vec3D{ 0.0f, 0.0f, 1.0f };

    return Cross(v, axis);
}
