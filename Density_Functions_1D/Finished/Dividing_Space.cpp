#include "Divide_Segment.h"

#include <thread>

void Dividing_Space ( multimap<double, double>const& cloud, double base_pt, int zone_limit, vector<Seg>& final_segs, vector<double>& max_radii, bool use_threads )
{
    pair<double, double> segment;
    
    double segment_size = cloud.rbegin()->first * 0.5;
    
    segment.first = base_pt - segment_size;
    segment.second = base_pt + segment_size;
    
    multimap<double, double> reduced_pts;
    multimap<double, double> remaining_pts;
    
    for (auto iter = cloud.begin(); iter != cloud.end(); ++iter)
    {
        if ((int)reduced_pts.size() <= -1) reduced_pts.insert( pair<double, double>( iter->first, iter->second ) );
        
        else remaining_pts.insert( pair<double, double>( iter->first, iter->second ) );
    }
    
    vector<Seg> starting_segs;
    
    Divide_Segment( reduced_pts, base_pt, zone_limit, segment, 1, starting_segs );
    
    vector<vector<Seg>> fin_segs( (int)starting_segs.size() );
    vector<thread> thr;
    
    thr.reserve( starting_segs.size() );
    
    for (int counter = 0; counter < fin_segs.size(); ++counter)
    {
        fin_segs[counter].reserve( 1000 );
    }
    
    if (use_threads)
    {
        for (int counter = 0; counter < starting_segs.size(); ++counter)
        {
            thr.push_back( thread( Divide_Segment, remaining_pts, base_pt, zone_limit, pair<double, double>( starting_segs[counter].left, starting_segs[counter].right ), starting_segs[counter].zone, ref( fin_segs[counter] ) ) );
        }
        
        for (int counter = 0; counter < starting_segs.size(); ++counter)
        {
            thr[counter].join();
        }
    }
    
    else
    {
        for (int counter = 0; counter < starting_segs.size(); ++counter)
        {
            Divide_Segment( remaining_pts, base_pt, zone_limit, pair<double, double>( starting_segs[counter].left, starting_segs[counter].right ), starting_segs[counter].zone, fin_segs[counter] );
        }
    }
    
    for (int counter_1 = 0; counter_1 < starting_segs.size(); ++counter_1)
    {
        final_segs.insert( final_segs.end(), fin_segs[counter_1].begin(), fin_segs[counter_1].end() );
    }
    
    vector<double> vec( zone_limit, 0 );
    max_radii = vec;
    
    for (int counter = 0; counter < final_segs.size(); ++counter)
    {
        double max_radius = final_segs[counter].dist;
        
        if (max_radii[final_segs[counter].zone - 1] < max_radius) max_radii[final_segs[counter].zone - 1] = max_radius;
    }
}
