#pragma once

class Vec2D
{
    public:
        float x, y;
    
        Vec2D(float, float);
    
        Vec2D operator-() const;
    
};
