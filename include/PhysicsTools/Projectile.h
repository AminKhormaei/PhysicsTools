#pragma once
#include "Particle.h"
#include "Vec2D.h"
#include "Vec3D.h"

template<typename TVec>
struct Projectile : Particle<TVec>
{
    TVec initialVelocity;
    
    void Launch(const TVec& velocity)
    {
        initialVelocity = velocity;
        this->velocity = velocity;
    }
};

using Projectile2D = Projectile<Vec2D>;
using Projectile3D = Projectile<Vec3D>;

