
// Vec3D.h
#pragma once

// Trivial/standard-layout: no virtuals, no destructor, 12 bytes, naturally
// aligned floats. That keeps it memcpy-able for SoA batching and safe to load
// 8 at a time with SIMD gathers/strided loads.
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
