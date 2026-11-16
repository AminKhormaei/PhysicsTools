#pragma once

class Vec3D
{
    public:
        float x, y, z;
    
        Vec3D(float, float, float);
        ~Vec3D();
    
        float get_x() const;
        float get_y() const;
        float get_z() const;
    
};
