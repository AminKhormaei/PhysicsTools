
// Vec2D.h
#pragma once

// Kept trivial/standard-layout on purpose: it must stay memcpy-able and
// lock-step laid out so it can be batched into SoA arrays and SIMD lanes.
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
