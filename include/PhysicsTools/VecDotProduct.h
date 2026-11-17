#pragma once
#pragma once
#include "Vec2D.h"
#include "Vec3D.h"

/**
 * @file Dot.h
 * @brief Dot product helpers for Vec2D and Vec3D.
 *
 * @details
 * The dot product measures how much two vectors point in the same direction.
 * - Result > 0: the vectors point roughly the same way (angle below 90 degrees).
 * - Result < 0: the vectors point roughly opposite ways (angle above 90 degrees).
 * - Result == 0: the vectors are perpendicular.
 *
 * For a unit vector `n`, `Dot(n, v)` is the signed length of `v` projected onto `n`.
 * Neither function modifies its arguments.
 *
 * @par Example
 * @code{.cpp}
 * float d2 = Dot(Vec2D(1.0f, 0.0f), Vec2D(0.0f, 1.0f));              // 0
 * float d3 = Dot(Vec3D(1.0f, 2.0f, 3.0f), Vec3D(4.0f, -5.0f, 6.0f)); // 12
 * @endcode
 */

/**
 * @brief Dot product of two 2D vectors.
 * @param a The first vector. Not modified.
 * @param b The second vector. Not modified.
 * @return `a.x * b.x + a.y * b.y`.
 *
 * @note `Dot(v, v)` equals the squared length of `v`, so no square root is needed
 *       to compare lengths.
 *
 * @code{.cpp}
 * float d = Dot(Vec2D(1.0f, 2.0f), Vec2D(3.0f, 4.0f));   // d == 11
 * @endcode
 *
 * @see Cross(const Vec2D&, const Vec2D&)
 */
inline float Dot(const Vec2D& a, const Vec2D& b) { return a.x * b.x + a.y * b.y; }

/**
 * @brief Dot product of two 3D vectors.
 * @param a The first vector. Not modified.
 * @param b The second vector. Not modified.
 * @return `a.x * b.x + a.y * b.y + a.z * b.z`.
 *
 * @note `Dot(v, v)` equals the squared length of `v`, so no square root is needed
 *       to compare lengths.
 *
 * @code{.cpp}
 * float d = Dot(Vec3D(1.0f, 2.0f, 3.0f), Vec3D(4.0f, 5.0f, 6.0f));   // d == 32
 * @endcode
 *
 * @see Cross(const Vec3D&, const Vec3D&)
 */
inline float Dot(const Vec3D& a, const Vec3D& b) { return a.x * b.x + a.y * b.y + a.z * b.z; }
