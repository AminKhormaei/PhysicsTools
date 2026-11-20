#pragma once

#include <vector>
#include "Projectile.h"

template <typename TProjectile>
class ParticleSystem
{
    std::vector<TProjectile> projectiles;

public:
    void Spawn(const TProjectile& p)
    {
        projectiles.push_back(p);
    }

    const std::vector<TProjectile>& GetAll() const
    {
        return projectiles;
    }

    // FIX 1: removed 'const' - Update mutates the container
    void Update(float dt)
    {
        // FIX 2: use a reference (auto&) so changes affect the real elements
        for (auto& p : projectiles)
        {
            p.age += dt;
            p.Integrate(dt);
        }

        // Swap-and-pop removal, iterating backwards
        for (int i = static_cast<int>(projectiles.size()) - 1; i >= 0; --i)
        {
            if (!projectiles[i].IsAlive())
            {
                projectiles[i] = projectiles.back();
                projectiles.pop_back();
            }
        }
    }
};

inline Projectile2D MakeProjectile2D(Vec2D position, Vec2D velocity, float life)
{
    Projectile2D p{};
    p.position    = position;
    p.velocity    = velocity;
    p.inverseMass = 1.0f;
    p.damping     = 0.99f;
    p.life        = life;
    p.age         = 0.0f;
    return p;
}

using ParticleSystem2D = ParticleSystem<Projectile2D>;
using ParticleSystem3D = ParticleSystem<Projectile3D>;