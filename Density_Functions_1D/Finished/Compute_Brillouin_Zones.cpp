#include "Dividing_Space.h"

#include <iostream>

void Compute_Brillouin_Zones ( multimap<double, double>const& cloud, double base_pt, int zone_limit, vector<vector<pair<double, double>>>& segs, vector<double>& max_radii, vector<double>& cell_volume, bool use_threads )
{
    vector<Seg> segments;
    segments.reserve( 3000 );
    
    Dividing_Space( cloud, base_pt, zone_limit, segments, max_radii, use_threads );
    
    cout << "Number of segments: " << segments.size() << "." << endl;
    
    segs.resize( zone_limit );
    
    for (int counter = 0; counter < segments.size(); ++counter)
    {
        pair<double, double> seg = pair<double, double>( segments[counter].left, segments[counter].right );
        
        segs[segments[counter].zone - 1].push_back( seg );
        
        cell_volume[segments[counter].zone - 1] += abs( seg.first - seg.second );
    }
}
