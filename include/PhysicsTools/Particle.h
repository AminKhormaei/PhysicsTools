#pragma once

#include "Vec2D.h"
#include "Vec3D.h"

template<typename TVec>
struct Particle
{
    TVec position;
    TVec velocity;
    TVec acceleration;
    float inverseMass; // Store 1/mass; zero = infinite mass (static body)
};

using Particle2D = Particle<Vec2D>;
using Particle3D = Particle<Vec3D>;
