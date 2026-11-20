#pragma once

#include <vector>
#include "Projectile.h"

template <typename TProjectile>
class ParticleSystem
{
    std::vector<TProjectile> projectiles;

    float spawnRate        = 0.0f; // particles per second (0 = emitter disabled)
    float spawnAccumulator = 0.0f; // accumulated time since last spawn
    TProjectile emitTemplate{};    // the particle that the emitter copies
    float gravity = 0.0f;

public:
    void SetGravity(float g) { gravity = g; }
    
    // Manual spawn (still works as before)
    void Spawn(const TProjectile& p)
    {
        projectiles.push_back(p);
    }

    // Configure the emitter: what to emit and how fast
    void SetEmitter(const TProjectile& templateParticle, float particlesPerSecond)
    {
        emitTemplate = templateParticle;
        spawnRate = particlesPerSecond;
    }

    const std::vector<TProjectile>& GetAll() const
    {
        return projectiles;
    }

    void Update(float dt)
    {
        // --- Emission ---
        if (spawnRate > 0.0f)
        {
            const float interval = 1.0f / spawnRate;
            spawnAccumulator += dt;

            while (spawnAccumulator >= interval)
            {
                Spawn(emitTemplate);
                spawnAccumulator -= interval; // keep the remainder, don't reset to 0
            }
        }

        // --- Simulation ---
        for (auto& p : projectiles)
        {
            p.velocity.y -= gravity * dt;
            p.age += dt;
            p.Integrate(dt);
        }

        // --- Removal (swap-and-pop, backwards) ---
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

// Put this AFTER the ParticleSystem class, in ParticleSystem.h
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