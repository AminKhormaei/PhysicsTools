#pragma once

#include "Vec2D.h"
#include "Vec3D.h"

/**
 * @brief A single physics particle — the smallest unit of simulation.
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
 * @tparam TVec The vector type: Vec2D for 2D simulations, Vec3D for 3D.
 */
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
