#pragma once

struct Vec2D
{
    Vec2D() = default;

    float x = 0.0f, y = 0.0f;

    Vec2D(float _x, float _y)
        : x(_x), y(_y) {}

    // Operator overloading
    Vec2D operator+(const Vec2D& other) const
    {
        return {x + other.x, y + other.y};
    }
    
    Vec2D operator-(const Vec2D& other) const
    {
        return {x - other.x, y - other.y};
    }
    
    Vec2D operator*(const float scalar) const
    {
        return {x * scalar, y * scalar};
    }
    
    Vec2D operator*=(const float scalar)
    {
        x *= scalar;
        y *= scalar;
        return *this;
    }
    
    Vec2D operator/(const float scalar) const
    {
        return { *this * (1.0f / scalar)};
    }
};
