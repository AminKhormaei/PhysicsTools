#pragma once

#include "Vec2D.h"
#include "Vec3D.h"

/**
 * @brief The smallest unit of simulation — a point mass with no rotation.
 *
 * This is a Plain Old Data (POD) struct, intentionally. No virtual methods,
 * no inheritance, no vtable pointer. Every byte is actual physics data.
 *
 * Design rationale:
 * - Template on TVec so the same struct serves 2D and 3D without duplication
 *   or wasted fields (the original class stored both 2D and 3D simultaneously).
 * - inverseMass instead of mass because the engine computes a = F * (1/m)
 *   every frame; storing the reciprocal avoids a division per particle per step.
 * - inverseMass = 0 means "infinite mass" (immovable/static body). This is a
 *   common convention: multiply by inverseMass in integration and static bodies
 *   simply don't move because 0 zeroes out the velocity update.
 *
 * Force Accumulator pattern:
 *   Each frame, forces are accumulated via AddForce().
 *   Integrate() applies them all at once, then ClearForces() resets for next frame.
 *
 * @tparam TVec The vector type: Vec2D for 2D simulations, Vec3D for 3D.
 */
template<typename TVec>
struct Particle
{
    TVec position;
    TVec velocity;
    TVec acceleration;
    TVec forceAccumulator;
    float inverseMass;
    float damping;
    
    void AddForce(const TVec& force)
    {
        forceAccumulator += force;
    }
    
    void ClearForces()
    {
        forceAccumulator = TVec{};
    }

    
    void Integrate(float dt)
    {
        if (inverseMass <= 0.0f) return;
        assert(dt > 0.0f);

        position += velocity * dt;
        
        TVec resultingAcceleration = acceleration + forceAccumulator * inverseMass;

        velocity += resultingAcceleration * dt;
        
        velocity *= powf(damping, dt);

        ClearForces();
    }
};

using Particle2D = Particle<Vec2D>;
using Particle3D = Particle<Vec3D>;


