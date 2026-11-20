#pragma once

#include "Vec2D.h"
#include "Vec3D.h"
#include "Integrator.h"

template<typename TVec>
struct Particle
{
    TVec position;
    TVec velocity;
    TVec acceleration;
    TVec forceAccumulator;

    float age;
    float life;

    float NormalizedAge() const
    {
        return age / life;
    }

    float inverseMass;
    float damping;

    bool IsAlive() const
    {
        return age < life;
    }

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
        Integrator<TVec>::Integrate(
            position,
            velocity,
            acceleration,
            forceAccumulator,
            inverseMass,
            damping,
            dt
        );
    }
};

using Particle2D = Particle<Vec2D>;
using Particle3D = Particle<Vec3D>;