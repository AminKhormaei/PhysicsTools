#pragma once
#include "Vec2D.h"
#include "Vec3D.h"

/**
 * @file VectorSubtract.h
 * @brief Free binary subtraction operators for Vec2D and Vec3D.
 *
 * @details
 * These operators return a new vector and leave both operands unchanged.
 * They are non-member `inline` functions, so they can be used in any
 * translation unit that includes this header.
 *
 * @par Example
 * @code{.cpp}
 * Vec2D a(4.0f, 6.0f);
 * Vec2D b(1.0f, 2.0f);
 * Vec2D d = a - b;   // d == (3, 4), a and b unchanged
 * @endcode
 */

/**
 * @brief Subtracts one 2D vector from another, component by component.
 * @param a The left-hand operand. Not modified.
 * @param b The vector to subtract. Not modified.
 * @return A new vector `(a.x - b.x, a.y - b.y)`.
 *
 * @code{.cpp}
 * Vec2D d = Vec2D(4.0f, 6.0f) - Vec2D(1.0f, 2.0f);   // (3, 4)
 * @endcode
 *
 * @see Vec2D::operator-=
 */
inline Vec2D operator-(const Vec2D& a, const Vec2D& b)
{
    return Vec2D{a.x - b.x, a.y - b.y};
}

/**
 * @brief Subtracts one 3D vector from another, component by component.
 * @param a The left-hand operand. Not modified.
 * @param b The vector to subtract. Not modified.
 * @return A new vector `(a.x - b.x, a.y - b.y, a.z - b.z)`.
 *
 * @code{.cpp}
 * Vec3D d = Vec3D(4.0f, 6.0f, 8.0f) - Vec3D(1.0f, 2.0f, 3.0f);   // (3, 4, 5)
 * @endcode
 *
 * @see Vec3D::operator-=
 */
inline Vec3D operator-(const Vec3D& a, const Vec3D& b)
{
    return Vec3D{a.x - b.x, a.y - b.y, a.z - b.z};
}
