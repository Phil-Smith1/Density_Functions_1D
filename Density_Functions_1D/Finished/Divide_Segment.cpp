#include "Max_Distance_To_Segment.h"
#include "Removing_Segments.h"
#include "Bisector_Intersect_Segment.h"
#include "Max_Radius_Of_Space.h"

#include <map>
#include <mutex>

void Divide_Segment ( multimap<double, double>const cloud, double base_pt, int zone_limit, pair<double, double> seg, int starting_zone, vector<Seg>& final_segs )
{
    vector<Seg> segs;
    segs.push_back( Seg( seg.first, seg.second, Max_Distance_To_Segment( base_pt, seg.first, seg.second ), starting_zone ) );
    
    double max_radius = 1e10;
    double distance = 0;
    
    vector<double> bisectors;
    bisectors.reserve( (int)cloud.size() );
    
    bool remove_segs = false;
    
    for (auto iter = cloud.begin(); iter != cloud.end(); ++iter)
    {
        double bisector = (base_pt + (*iter).second) * 0.5;
        
        distance = abs( base_pt - bisector );
                
        if (max_radius < distance + tiny_num) break;
        
        {
            mutex m1;
            
            lock_guard<mutex> lock_guard( m1 );
            
            if (remove_segs) Removing_Segments( base_pt, distance, segs, final_segs, zone_limit );
        }
        
        bisectors.push_back( bisector );
        
        if ((int)segs.size() == 0) break;
        
        int intersect = Bisector_Intersect_Segment( seg, base_pt, bisector );
        
        if (intersect == -1)
        {
            for (int counter = 0; counter < segs.size(); ++counter)
            {
                segs[counter].zone += 1;
            }
            
            remove_segs = true;
            
            continue;
        }
        
        else if (intersect == 1)
        {
            remove_segs = false;
            continue;
        }
        
        else
        {
            remove_segs = true;
            
            vector<Seg> new_segs;
            new_segs.reserve( (int)segs.size() );
            
            for (int counter_1 = 0; counter_1 < segs.size(); ++counter_1)
            {
                if (bisector < segs[counter_1].left + tiny_num || bisector > segs[counter_1].right - tiny_num)
                {
                    if (base_pt < bisector && bisector < segs[counter_1].left + tiny_num)
                    {
                        ++segs[counter_1].zone;
                        continue;
                    }
                    
                    else if (base_pt > bisector && bisector > segs[counter_1].right - tiny_num)
                    {
                        ++segs[counter_1].zone;
                        continue;
                    }
                    
                    else continue;
                }
                
                else
                {
                    pair<double, double> pos_seg, neg_seg;
                    
                    if (base_pt < bisector)
                    {
                        pos_seg.first = segs[counter_1].left;
                        pos_seg.second = bisector;
                        neg_seg.first = bisector;
                        neg_seg.second = segs[counter_1].right;
                    }
                    
                    else
                    {
                        pos_seg.first = bisector;
                        pos_seg.second = segs[counter_1].right;
                        neg_seg.first = segs[counter_1].left;
                        neg_seg.second = bisector;
                    }
                    
                    double dist_pos_seg = Max_Distance_To_Segment( base_pt, pos_seg.first, pos_seg.second );
                    
                    segs[counter_1].left = pos_seg.first;
                    segs[counter_1].right = pos_seg.second;
                    segs[counter_1].dist = dist_pos_seg;
                    
                    if (segs[counter_1].zone + 1 <= zone_limit)
                    {
                        double dist_neg_seg = Max_Distance_To_Segment( base_pt, neg_seg.first, neg_seg.second );
                        
                        new_segs.push_back( Seg( neg_seg.first, neg_seg.second, dist_neg_seg, segs[counter_1].zone + 1 ) );
                    }
                }
            }
            
            segs.insert( segs.end(), new_segs.begin(), new_segs.end() );
        }
        
        max_radius = Max_Radius_Of_Space( segs );
    }
    
    {
        mutex m1;
        
        lock_guard<mutex> lock_guard( m1 );
        
        Removing_Segments( base_pt, distance, segs, final_segs, zone_limit );
        
        final_segs.insert( final_segs.end(), segs.begin(), segs.end() );
    }
}
