#pragma once

class Vec3D
{
    float x_, y_, z_;
    
    public:
        Vec3D(float, float, float);
        ~Vec3D();
    
        float get_x() const;
        float get_y() const;
        float get_z() const;
    
};
