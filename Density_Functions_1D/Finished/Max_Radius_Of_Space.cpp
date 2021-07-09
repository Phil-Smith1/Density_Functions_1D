#include "Seg.h"

#include <vector>

using namespace std;

double Max_Radius_Of_Space ( vector<Seg>const& segs )
{
    double max_radius = 0;
    
    for (int counter = 0; counter < segs.size(); ++counter)
    {
        if (segs[counter].dist > max_radius) max_radius = segs[counter].dist;
    }
    
    return max_radius;
}
