#pragma once
#include "Vec2D.h"
#include "Vec3D.h"
/**
 * @file VectorOperators.h
 * @brief Free binary addition operators for Vec2D and Vec3D.
 *
 * @details
 * These operators return a new vector and leave both operands unchanged.
 * They are defined as non-member `inline` functions so they can be used
 * in any translation unit that includes this header.
 *
 * @par Example
 * @code{.cpp}
 * Vec2D a(1.0f, 2.0f);
 * Vec2D b(3.0f, 4.0f);
 * Vec2D c = a + b;   // c == (4, 6), a and b unchanged
 * @endcode
 */

/**
 * @brief Adds two 2D vectors component by component.
 * @param a The left-hand operand. Not modified.
 * @param b The right-hand operand. Not modified.
 * @return A new vector `(a.x + b.x, a.y + b.y)`.
 *
 * @code{.cpp}
 * Vec2D sum = Vec2D(1.0f, 2.0f) + Vec2D(3.0f, 4.0f);   // (4, 6)
 * @endcode
 *
 * @see Vec2D::operator+=
 */

inline Vec2D operator+(const Vec2D& a, const Vec2D& b) { return Vec2D{a.x + b.x, a.y + b.y}; }
inline Vec3D operator+(const Vec3D& a, const Vec3D& b) { return Vec3D{a.x + b.x, a.y + b.y, a.z + b.z}; }
