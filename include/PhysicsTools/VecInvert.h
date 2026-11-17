#pragma once

template <typename T>
class VecInvert
{
    T value_;
    
    public:
        explicit VecInvert(T value) : value_(value) {}
    
        operator T() const {return -value_;}
        
};
