#include "Seg.h"

#include <vector>

using namespace std;

#ifndef tiny_number
#define tiny_number
const double tiny_num = 1e-10;
#endif

void Removing_Segments ( double const& base_pt, double distance, vector<Seg>& segs, vector<Seg>& final_segs, int zone_limit )
{
    vector<Seg> remaining_segs;
    remaining_segs.reserve( segs.size() );
    vector<Seg> inside_segs;
    inside_segs.reserve( segs.size() );
    
    for (int counter = 0; counter < segs.size(); ++counter)
    {
        if (segs[counter].zone <= zone_limit)
        {
            if (segs[counter].dist < distance + tiny_num) inside_segs.push_back( segs[counter] );
            
            else remaining_segs.push_back( segs[counter] );
        }
    }
    
    segs = remaining_segs;
    final_segs.insert( final_segs.end(), inside_segs.begin(), inside_segs.end() );
}
