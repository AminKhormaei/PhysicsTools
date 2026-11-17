
// Vec2D.h
#pragma once
/**
 * @file Vec2D.h
 * @brief A minimal 2D vector of single-precision floats.
 *
 * @details
 * Vec2D is a plain, trivially copyable type with a fixed memory layout:
 * two consecutive floats, `x` then `y`. It is kept this way on purpose so
 * that arrays of Vec2D can be memcpy'd, batched into Structure-of-Arrays
 * (SoA) buffers, or processed in SIMD lanes.
 *
 * Design rules:
 * - Do not add virtual functions, base classes, or non-static data members.
 * - Keep all state in `x` and `y`.
 *
 * @par Example
 * @code{.cpp}
 * Vec2D position(10.0f, 5.0f);
 * Vec2D offset(1.0f, -0.5f);
 *
 * position += offset;     // position == (11, 4.5)
 * position -= Vec2D(1.0f, 1.0f);
 * position *= 2.0f;       // scale both components
 * position /= 4.0f;       // divide both components
 * Vec2D opposite = -position;
 * @endcode
 */
class Vec2D
{
public:
    float x, y;

    constexpr Vec2D() = default;
    constexpr Vec2D(float x, float y) : x(x), y(y) {}

    constexpr Vec2D operator-() const
    {
        return Vec2D(-x, -y);
    }

    // In-place compound operators: these forward directly to the scalars, so
    // they emit a single add/mul per component with no temporary.
    constexpr Vec2D& operator+=(const Vec2D& o) { x += o.x; y += o.y; return *this; }
    constexpr Vec2D& operator-=(const Vec2D& o) { x -= o.x; y -= o.y; return *this; }
    constexpr Vec2D& operator*=(float s) { x *= s; y *= s; return *this; }
    constexpr Vec2D& operator/=(float s) { const float r = 1.0f / s; x *= r; y *= r; return *this; }
};
