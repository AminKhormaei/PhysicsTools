#pragma once
#pragma once

#include <cassert>
#include <cmath>

template <typename TVec>
struct Integrator
{
    static void Integrate(
        TVec& position,
        TVec& velocity,
        const TVec& acceleration,
        TVec& forceAccumulator,
        float inverseMass,
        float damping,
        float dt)
    {
        if (inverseMass <= 0.0f) return;
        if (dt <= 0.0f) return;

        assert(dt > 0.0f);

        // Update position.
        position += velocity * dt;

        // Calculate resulting acceleration.
        TVec resultingAcceleration =
            acceleration + forceAccumulator * inverseMass;

        // Update velocity.
        velocity += resultingAcceleration * dt;

        // Apply damping.
        velocity *= powf(damping, dt);

        // Clear accumulated forces.
        forceAccumulator = TVec{};
    }
};