/**
* @file Random.h
 * @brief Tiny header-only random number generator (xorshift32).
 *
 * The generator keeps a single 4-byte state that is shared by the whole
 * program. It is seeded automatically from the clock on the first call,
 * so no setup code is needed.
 *
 * @note Not thread-safe and not suitable for cryptography.
 * @usecase ball.Launch(Vec2D{ RandomRange(5.0f, 15.0f), RandomRange(3.0f, 10.0f) });
 */
#pragma once
#include <cstdint>
#include <chrono>

/**
 * @brief Advances the generator by one step and returns the raw value.
 *
 * On the first call the internal state is seeded from
 * std::chrono::steady_clock, so every program run produces a different
 * sequence.
 *
 * @return A pseudo-random 32-bit unsigned integer in [1, 2^32 - 1].
 * @note The state can never be 0, because xorshift would then return 0 forever.
 */
inline uint32_t NextU32()
{
    // Initialized once, on first call, from the clock
    static uint32_t state = []{
        uint32_t s = (uint32_t)std::chrono::steady_clock::now()
                         .time_since_epoch().count();
        return s ? s : 1u;   // xorshift must never have state == 0
    }();

    state ^= state << 13;
    state ^= state >> 17;
    state ^= state << 5;
    return state;
}

/**
 * @brief Returns a random float in the half-open range [0, 1).
 *
 * Only the top 24 bits of NextU32() are used, because a float has a
 * 24-bit mantissa. This keeps the result strictly below 1.0.
 *
 * @return A pseudo-random float, 0 <= value < 1.
 */
inline float Random01()
{
    return (NextU32() >> 8) * (1.0f / 16777216.0f);   // 1 / 2^24
}

/**
 * @brief Returns a random float in the half-open range [min, max).
 *
 * @param min Lower bound (inclusive).
 * @param max Upper bound (exclusive). Should be >= @p min.
 * @return A pseudo-random float, min <= value < max.
 *
 * @code
 * ball.Launch(Vec2D{ RandomRange(5.0f, 15.0f), RandomRange(3.0f, 10.0f) });
 * @endcode
 */
inline float RandomRange(float min, float max)
{
    return min + (max - min) * Random01();
}