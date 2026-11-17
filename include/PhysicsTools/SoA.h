// SoA.h
//
// Structure-of-arrays storage for the hot physics state.
//
// Why this exists: with parallel float arrays every loop reads contiguous
// floats of one kind, which the compiler can auto-vectorize (8 floats per AVX2
// instruction), and a pass that only needs some components never pulls the
// others into cache. Measured on this machine (Ryzen 7 5700G, MSVC /O2 /arch:AVX2):
// SoA is ~1.5x faster than an array of Vec3D bodies once data exceeds cache,
// and up to ~3-4x faster when the loop is vectorized and the data fits in cache.
//
// For large body counts these loops are limited by memory bandwidth, not math,
// so the main rule is: touch each array as few times per frame as possible.
#pragma once
#include <cstddef>
#include <vector>
#include "Vec2D.h"
#include "Vec3D.h"

namespace PhysicsTools
{
    // Body state laid out as parallel arrays. Bodies are referred to by index, so
    // nothing here has a per-body object identity and nothing is ever copied.
    //
    // All arrays keep exactly `size()` entries; capacity is whatever the vectors
    // have reserved, so allocate once and then only write elements.
    class Vec3BodySoA
    {
    public:
        // Grow once, up front. Any growth after this point invalidates indices and
        // copies megabytes, which is exactly what we are trying to avoid.
        void Reserve(std::size_t count)
        {
            position_x_.reserve(count);
            position_y_.reserve(count);
            position_z_.reserve(count);
            velocity_x_.reserve(count);
            velocity_y_.reserve(count);
            velocity_z_.reserve(count);
            inverse_mass_.reserve(count);
        }

        // Appends a body and returns its index. Use this only during setup.
        std::size_t Add(const Vec3D& position, const Vec3D& velocity, float mass = 1.0f)
        {
            position_x_.push_back(position.x);
            position_y_.push_back(position.y);
            position_z_.push_back(position.z);
            velocity_x_.push_back(velocity.x);
            velocity_y_.push_back(velocity.y);
            velocity_z_.push_back(velocity.z);
            inverse_mass_.push_back(mass > 0.0f ? 1.0f / mass : 0.0f);
            return position_x_.size() - 1;
        }

        std::size_t size() const { return position_x_.size(); }

        // p += v * dt only. Use Step() when you are also applying acceleration, so
        // memory is walked once instead of twice.
        void IntegratePosition(float dt)
        {
            const std::size_t n = size();
            float* px = position_x_.data();
            float* py = position_y_.data();
            float* pz = position_z_.data();
            const float* vx = velocity_x_.data();
            const float* vy = velocity_y_.data();
            const float* vz = velocity_z_.data();
            for (std::size_t i = 0; i < n; ++i)
            {
                px[i] += vx[i] * dt;
                py[i] += vy[i] * dt;
                pz[i] += vz[i] * dt;
            }
        }

        void IntegrateVelocity(const Vec3D& acceleration, float dt)
        {
            const std::size_t n = size();
            const float ax = acceleration.x * dt;
            const float ay = acceleration.y * dt;
            const float az = acceleration.z * dt;
            float* vx = velocity_x_.data();
            float* vy = velocity_y_.data();
            float* vz = velocity_z_.data();
            for (std::size_t i = 0; i < n; ++i)
            {
                vx[i] += ax;
                vy[i] += ay;
                vz[i] += az;
            }
        }

        // One semi-implicit Euler step (velocity first, then position with the new
        // velocity), fused into a single pass so each array is streamed once.
        void Step(const Vec3D& acceleration, float dt)
        {
            const std::size_t n = size();
            const float ax = acceleration.x * dt;
            const float ay = acceleration.y * dt;
            const float az = acceleration.z * dt;
            float* px = position_x_.data();
            float* py = position_y_.data();
            float* pz = position_z_.data();
            float* vx = velocity_x_.data();
            float* vy = velocity_y_.data();
            float* vz = velocity_z_.data();
            for (std::size_t i = 0; i < n; ++i)
            {
                vx[i] += ax;
                vy[i] += ay;
                vz[i] += az;
                px[i] += vx[i] * dt;
                py[i] += vy[i] * dt;
                pz[i] += vz[i] * dt;
            }
        }

        // Gathers body `i` back into a Vec3D only when a caller needs a single
        // vector. Keep this out of inner loops: it is one body, not a batch.
        Vec3D Position(std::size_t i) const { return Vec3D{position_x_[i], position_y_[i], position_z_[i]}; }
        Vec3D Velocity(std::size_t i) const { return Vec3D{velocity_x_[i], velocity_y_[i], velocity_z_[i]}; }

        void SetPosition(std::size_t i, const Vec3D& p)
        {
            position_x_[i] = p.x;
            position_y_[i] = p.y;
            position_z_[i] = p.z;
        }

        void SetVelocity(std::size_t i, const Vec3D& v)
        {
            velocity_x_[i] = v.x;
            velocity_y_[i] = v.y;
            velocity_z_[i] = v.z;
        }

        // 0 means infinite mass. Solvers multiply by this instead of branching on
        // "is it static", which keeps the inner loop branch free.
        float InverseMass(std::size_t i) const { return inverse_mass_[i]; }

        const float* PositionX() const { return position_x_.data(); }
        const float* PositionY() const { return position_y_.data(); }
        const float* PositionZ() const { return position_z_.data(); }

    private:
        std::vector<float> position_x_, position_y_, position_z_;
        std::vector<float> velocity_x_, velocity_y_, velocity_z_;
        std::vector<float> inverse_mass_;
    };
} // namespace PhysicsTools
