#pragma once
#include "Vec2D.h"
#include "Vec3D.h"

/**
 * @file VecScalarMultiplier.h
 * @brief Free multiplication operators: scalar times vector and vector times scalar.
 *
 * @details
 * Both orderings are provided, so `2.0f * v` and `v * 2.0f` compile without
 * implicit conversions. Each operator returns a new vector and leaves its
 * operands unchanged.
 *
 * The functions are kept trivial so that an expression such as `p += v * dt`
 * can be optimized into the compound assignment without a visible temporary.
 *
 * @par Example
 * @code{.cpp}
 * Vec2D a = 2.0f * Vec2D(1.0f, -3.0f);    // (2, -6)
 * Vec2D b = Vec2D(1.0f, -3.0f) * 0.5f;    // (0.5, -1.5)
 * @endcode
 */

/**
 * @brief Multiplies a scalar by a 2D vector.
 * @param s The scale factor.
 * @param v The vector. Not modified.
 * @return A new vector `(s * v.x, s * v.y)`.
 *
 * @code{.cpp}
 * Vec2D r = 3.0f * Vec2D(1.0f, 2.0f);   // (3, 6)
 * @endcode
 *
 * @see operator*(const Vec2D&, float)
 */
inline Vec2D operator*(float s, const Vec2D& v) { return Vec2D{ s * v.x, s * v.y }; }

/**
 * @brief Multiplies a 2D vector by a scalar.
 * @param v The vector. Not modified.
 * @param s The scale factor.
 * @return A new vector `(v.x * s, v.y * s)`.
 *
 * @code{.cpp}
 * Vec2D r = Vec2D(1.0f, 2.0f) * 3.0f;   // (3, 6)
 * @endcode
 *
 * @see operator*(float, const Vec2D&)
 */
inline Vec2D operator*(const Vec2D& v, float s) { return Vec2D{ v.x * s, v.y * s }; }

/**
 * @brief Multiplies a scalar by a 3D vector.
 * @param s The scale factor.
 * @param v The vector. Not modified.
 * @return A new vector `(s * v.x, s * v.y, s * v.z)`.
 *
 * @code{.cpp}
 * Vec3D r = 2.0f * Vec3D(1.0f, -2.0f, 3.0f);   // (2, -4, 6)
 * @endcode
 *
 * @see operator*(const Vec3D&, float)
 */
inline Vec3D operator*(float s, const Vec3D& v) { return Vec3D{ s * v.x, s * v.y, s * v.z }; }

/**
 * @brief Multiplies a 3D vector by a scalar.
 * @param v The vector. Not modified.
 * @param s The scale factor.
 * @return A new vector `(v.x * s, v.y * s, v.z * s)`.
 *
 * @code{.cpp}
 * Vec3D r = Vec3D(1.0f, -2.0f, 3.0f) * 2.0f;   // (2, -4, 6)
 * @endcode
 *
 * @see operator*(float, const Vec3D&)
 */
inline Vec3D operator*(const Vec3D& v, float s) { return Vec3D{ v.x * s, v.y * s, v.z * s }; }
