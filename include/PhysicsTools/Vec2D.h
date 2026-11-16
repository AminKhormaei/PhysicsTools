#pragma once

class Vec2D
{
    float x_, y_;
    
    public:
        Vec2D(float x, float y);
        
        float GetX() const;
        float GetY() const;
};
