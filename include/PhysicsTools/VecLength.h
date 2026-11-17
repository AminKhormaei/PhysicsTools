#pragma once
#include <cmath>
#include "Vec3D.h"
#include "Vec2D.h"

/**
 * @file Length.h
 * @brief Length, squared length, inverse length, and normalization helpers
 *        for Vec2D and Vec3D.
 *
 * @details
 * LengthSquared is the primitive. It is branch-free and needs no square root.
 * Use it when comparing distances, for example in broad-phase or distance
 * rejection:
 * @code{.cpp}
 * // Length(a - b) < r  is equivalent to  LengthSquared(a - b) < r * r
 * @endcode
 * Only take the square root when you need the actual magnitude.
 *
 * None of these functions modify their input, except the in-place
 * Normalize overloads, which are documented as such.
 */

/**
 * @brief Squared length of a 2D vector.
 * @param v The vector. Not modified.
 * @return `v.x * v.x + v.y * v.y`.
 *
 * @note No square root is computed. Prefer this when comparing lengths
 *       against a threshold: compare with `r * r` instead of `r`.
 *
 * @code{.cpp}
 * float s = LengthSquared(Vec2D(3.0f, 4.0f));   // s == 25
 * @endcode
 *
 * @see Length(const Vec2D&)
 */
inline float LengthSquared(const Vec2D& v) { return v.x * v.x + v.y * v.y; }

/**
 * @brief Squared length of a 3D vector.
 * @param v The vector. Not modified.
 * @return `v.x * v.x + v.y * v.y + v.z * v.z`.
 *
 * @note No square root is computed. Prefer this when comparing lengths
 *       against a threshold: compare with `r * r` instead of `r`.
 *
 * @code{.cpp}
 * float s = LengthSquared(Vec3D(1.0f, 2.0f, 2.0f));   // s == 9
 * @endcode
 *
 * @see Length(const Vec3D&)
 */
inline float LengthSquared(const Vec3D& v) { return v.x * v.x + v.y * v.y + v.z * v.z; }

/**
 * @brief Length (magnitude) of a 2D vector.
 * @param v The vector. Not modified.
 * @return `sqrt(LengthSquared(v))`.
 *
 * @note Calls a square root. If you only compare lengths, use LengthSquared.
 *
 * @code{.cpp}
 * float len = Length(Vec2D(3.0f, 4.0f));   // len == 5
 * @endcode
 */
inline float Length(const Vec2D& v) { return std::sqrt(LengthSquared(v)); }

/**
 * @brief Length (magnitude) of a 3D vector.
 * @param v The vector. Not modified.
 * @return `sqrt(LengthSquared(v))`.
 *
 * @note Calls a square root. If you only compare lengths, use LengthSquared.
 *
 * @code{.cpp}
 * float len = Length(Vec3D(1.0f, 2.0f, 2.0f));   // len == 3
 * @endcode
 */
inline float Length(const Vec3D& v) { return std::sqrt(LengthSquared(v)); }

/**
 * @brief Reciprocal of the length of a 2D vector, with a safe zero case.
 * @param v The vector. Not modified.
 * @return `1 / Length(v)`, or `0` if `v` is the zero vector.
 *
 * @details
 * Returning 0 for a zero vector means callers can multiply by this value
 * without a separate zero check. It never returns `inf` or `NaN` for a
 * zero vector.
 *
 * @code{.cpp}
 * float inv = InvLength(Vec2D(3.0f, 4.0f));   // inv == 0.2
 * @endcode
 */
inline float InvLength(const Vec2D& v)
{
    const float lenSq = LengthSquared(v);
    return lenSq > 0.0f ? 1.0f / std::sqrt(lenSq) : 0.0f;
}


/**
 * @brief Reciprocal of the length of a 3D vector, with a safe zero case.
 * @param v The vector. Not modified.
 * @return `1 / Length(v)`, or `0` if `v` is the zero vector.
 *
 * @details
 * Returning 0 for a zero vector means callers can multiply by this value
 * without a separate zero check. It never returns `inf` or `NaN` for a
 * zero vector.
 *
 * @code{.cpp}
 * float inv = InvLength(Vec3D(0.0f, 0.0f, 2.0f));   // inv == 0.5
 * @endcode
 */
inline float InvLength(const Vec3D& v)
{
    const float lenSq = LengthSquared(v);
    return lenSq > 0.0f ? 1.0f / std::sqrt(lenSq) : 0.0f;
}

/**
 * @brief Normalizes a 2D vector in place so its length becomes 1.
 * @param v The vector to normalize. **Modified in place.**
 *
 * @details
 * A zero vector stays zero. It is not turned into `NaN`.
 * No temporary object is created, so the caller's storage is reused.
 *
 * @code{.cpp}
 * Vec2D dir(3.0f, 4.0f);
 * Normalize(dir);   // dir == (0.6, 0.8)
 * @endcode
 *
 * @see Normalized(const Vec2D&)
 */
inline void Normalize(Vec2D& v)
{
    const float inv = InvLength(v);
    v.x *= inv;
    v.y *= inv;
}


/**
 * @brief Normalizes a 3D vector in place so its length becomes 1.
 * @param v The vector to normalize. **Modified in place.**
 *
 * @details
 * A zero vector stays zero. It is not turned into `NaN`.
 * No temporary object is created, so the caller's storage is reused.
 *
 * @code{.cpp}
 * Vec3D dir(0.0f, 3.0f, 4.0f);
 * Normalize(dir);   // dir == (0, 0.6, 0.8)
 * @endcode
 *
 * @see Normalized(const Vec3D&)
 */
inline void Normalize(Vec3D& v)
{
    const float inv = InvLength(v);
    v.x *= inv;
    v.y *= inv;
    v.z *= inv;
}

/**
 * @brief Returns a normalized copy of a 2D vector.
 * @param v The source vector. Not modified.
 * @return A new vector with length 1, or the zero vector if `v` is zero.
 *
 * @code{.cpp}
 * Vec2D n = Normalized(Vec2D(3.0f, 4.0f));   // n == (0.6, 0.8), source unchanged
 * @endcode
 *
 * @see Normalize(Vec2D&)
 */
inline Vec2D Normalized(const Vec2D& v) { Vec2D out = v; Normalize(out); return out; }

/**
 * @brief Returns a normalized copy of a 3D vector.
 * @param v The source vector. Not modified.
 * @return A new vector with length 1, or the zero vector if `v` is zero.
 *
 * @code{.cpp}
 * Vec3D n = Normalized(Vec3D(0.0f, 3.0f, 4.0f));   // n == (0, 0.6, 0.8), source unchanged
 * @endcode
 *
 * @see Normalize(Vec3D&)
 */
inline Vec3D Normalized(const Vec3D& v) { Vec3D out = v; Normalize(out); return out; }
