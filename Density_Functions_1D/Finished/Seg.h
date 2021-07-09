#pragma once

class Seg
{
    public:
    
    int zone;
    double dist;
    double left;
    double right;
    
    Seg ( double l, double r, double d, int z );
    
    Seg();
    ~Seg();
};
