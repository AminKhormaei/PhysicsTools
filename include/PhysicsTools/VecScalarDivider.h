// VecScalarDivider.h
#pragma once
#include <cassert>
#include "Vec2D.h"
#include "Vec3D.h"
#include "VecScalarMultiplier.h"

/**
 * @file VecScalarDivider.h
 * @brief Free division operators: vector divided by a scalar.
 *
 * @details
 * Both operators return a new vector and leave the operand unchanged.
 * Internally, `v / k` is computed as `v * (1 / k)`, so the reciprocal is
 * calculated once and then multiplied into each component.
 *
 * The zero check is an `assert`, not a runtime branch. On the hot path, a
 * predictable branch still costs a compare and a jump per component, and the
 * assert documents the precondition. In release builds (`NDEBUG` defined),
 * the assert is removed, so dividing by zero produces `inf` or `NaN`.
 *
 * For in-place division without a temporary, use `operator/=` on the
 * vector classes.
 *
 * @par Example
 * @code{.cpp}
 * Vec2D a = Vec2D(4.0f, 8.0f) / 2.0f;   // (2, 4)
 * Vec3D b = Vec3D(3.0f, 6.0f, 9.0f) / 3.0f;   // (1, 2, 3)
 * @endcode
 *
 * @see Vec2D::operator/=
 * @see Vec3D::operator/=
 */

/**
 * @brief Divides a 2D vector by a scalar.
 * @param v The vector to divide. Not modified.
 * @param k The divisor. Must not be zero. Checked by `assert` in debug builds.
 * @return A new vector `v * (1 / k)`.
 *
 * @warning If `k == 0` in a release build, the result contains `inf` or `NaN`.
 * @note The result can differ from a true division by about 1 ULP, because
 *       the reciprocal is multiplied rather than dividing each component.
 *
 * @code{.cpp}
 * Vec2D half = Vec2D(3.0f, -5.0f) / 2.0f;   // (1.5, -2.5)
 * @endcode
 */
inline Vec2D operator/(const Vec2D& v, float k)
{
    assert(k != 0.0f && "Vec2D division by zero");
    return v * (1.0f / k);
}

/**
 * @brief Divides a 3D vector by a scalar.
 * @param v The vector to divide. Not modified.
 * @param k The divisor. Must not be zero. Checked by `assert` in debug builds.
 * @return A new vector `v * (1 / k)`.
 *
 * @warning If `k == 0` in a release build, the result contains `inf` or `NaN`.
 * @note The result can differ from a true division by about 1 ULP, because
 *       the reciprocal is multiplied rather than dividing each component.
 *
 * @code{.cpp}
 * Vec3D third = Vec3D(3.0f, -6.0f, 9.0f) / 3.0f;   // (1, -2, 3)
 * @endcode
 */
inline Vec3D operator/(const Vec3D& v, float k)
{
    assert(k != 0.0f && "Vec3D division by zero");
    return v * (1.0f / k);
}
