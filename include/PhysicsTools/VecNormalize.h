// VecNormalize.h
#pragma once

#include "Vec2D.h"
#include "Vec3D.h"
#include <cmath>

/**
 * @file VecNormalize.h
 * @brief Non-mutating normalization helpers for Vec2D and Vec3D.
 *
 * @details
 * Provides `normalized()` overloads that return a unit-length copy of a
 * vector. The input is never modified.
 *
 * Degenerate input (a length below kNormEpsilon) returns the zero vector
 * instead of producing `inf` or `NaN`.
 *
 * @note The function names are lowercase `normalized`. The header Length.h
 *       provides `Normalized` (capitalized) with the same purpose but only
 *       treats an exact zero vector as degenerate. Do not include both
 *       headers in the same translation unit and mix them up.
 */

/**
 * @brief Threshold below which a vector length is treated as zero.
 *
 * @details
 * Used by normalized() to detect degenerate input. Lengths smaller than this
 * value return the zero vector.
 *
 * @note This is an absolute threshold. For very small or very large vectors
 *       you may need a different value.
 */
static constexpr float kNormEpsilon = 1e-8f;


/**
 * @brief Returns a unit-length copy of a 2D vector.
 * @param v The source vector. Not modified.
 * @return `v / |v|` if `|v| >= kNormEpsilon`, otherwise `Vec2D(0, 0)`.
 *
 * @details
 * The function does not divide by a value near zero. For a degenerate
 * input it returns the zero vector, so the caller can check the result
 * with a zero test if it needs to detect that case.
 *
 * @code{.cpp}
 * Vec2D n = normalized(Vec2D(3.0f, 4.0f));   // n == (0.6, 0.8)
 * Vec2D z = normalized(Vec2D(0.0f, 0.0f));   // z == (0, 0)
 * @endcode
 *
 * @see kNormEpsilon
 */
inline Vec2D normalized(const Vec2D& v)
{
    const float len = sqrtf(v.x * v.x + v.y * v.y);
    if (len < kNormEpsilon) return Vec2D(0.f, 0.f);
    const float inv = 1.0f / len;
    return Vec2D(v.x * inv, v.y * inv);
}


/**
 * @brief Returns a unit-length copy of a 3D vector.
 * @param v The source vector. Not modified.
 * @return `v / |v|` if `|v| >= kNormEpsilon`, otherwise `Vec3D(0, 0, 0)`.
 *
 * @details
 * The function does not divide by a value near zero. For a degenerate
 * input it returns the zero vector.
 *
 * @code{.cpp}
 * Vec3D n = normalized(Vec3D(0.0f, 3.0f, 4.0f));   // n == (0, 0.6, 0.8)
 * Vec3D z = normalized(Vec3D(0.0f, 0.0f, 0.0f));   // z == (0, 0, 0)
 * @endcode
 *
 * @see kNormEpsilon
 */
inline Vec3D normalized(const Vec3D& v)
{
    const float len = sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
    if (len < kNormEpsilon) return Vec3D(0.f, 0.f, 0.f);
    const float inv = 1.0f / len;
    return Vec3D(v.x * inv, v.y * inv, v.z * inv);
}
