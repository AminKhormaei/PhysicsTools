
// Vec3D.h
#pragma once


/**
 * @file Vec3D.h
 * @brief A minimal 3D vector of single-precision floats.
 *
 * @details
 * Vec3D is a plain, trivially copyable type with a fixed memory layout:
 * three consecutive floats, `x`, `y`, then `z`, for a total of 12 bytes
 * with natural float alignment. It has no virtual functions, no destructor,
 * and no hidden state, so it can be memcpy'd, batched into Structure-of-Arrays
 * (SoA) buffers, or loaded in SIMD lanes.
 *
 * Design rules:
 * - Do not add virtual functions, base classes, or non-static data members.
 * - Keep all state in `x`, `y`, and `z`.
 *
 * @par Example
 * @code{.cpp}
 * Vec3D position(10.0f, 5.0f, 0.0f);
 * Vec3D offset(1.0f, -0.5f, 2.0f);
 *
 * position += offset;     // position == (11, 4.5, 2)
 * position -= Vec3D(1.0f, 1.0f, 1.0f);
 * position *= 2.0f;       // scale all components
 * position /= 4.0f;       // divide all components
 * Vec3D opposite = -position;
 * @endcode
 */
class Vec3D
{
public:
    float x, y, z;

    constexpr Vec3D() = default;

    constexpr Vec3D(float x, float y, float z)
        : x(x), y(y), z(z) {}

    constexpr Vec3D operator-() const
    {
        return Vec3D(-x, -y, -z);
    }

    constexpr Vec3D& operator+=(const Vec3D& o) { x += o.x; y += o.y; z += o.z; return *this; }
    constexpr Vec3D& operator-=(const Vec3D& o) { x -= o.x; y -= o.y; z -= o.z; return *this; }
    constexpr Vec3D& operator*=(float s) { x *= s; y *= s; z *= s; return *this; }
    constexpr Vec3D& operator/=(float s) { const float r = 1.0f / s; x *= r; y *= r; z *= r; return *this; }
};
