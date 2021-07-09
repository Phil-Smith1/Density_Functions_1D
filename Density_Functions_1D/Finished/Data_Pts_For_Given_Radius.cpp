#include "Input.h"
#include "Disk_Segment_Intersection.h"

void Data_Pts_For_Given_Radius ( Input const input, int sample, vector<double>const base_pts, vector<vector<vector<pair<double, double>>>>const segs, vector<double>const cell_volume, vector<vector<double>>const max_radii, vector<double>& results )
{
    double radius = sample / (double)input.sample_rate;

    results[0] = radius;
    
    vector<double> volume( input.zone_limit, 0 );
    
    for (int counter_1 = 0; counter_1 < base_pts.size(); ++counter_1)
    {
        pair<double, double> c( base_pts[counter_1] - radius, base_pts[counter_1] + radius );
            
        for (int counter_2 = 0; counter_2 < input.zone_limit; ++counter_2)
        {
            if (max_radii[counter_1][counter_2] < radius + tiny_num)
            {
                for (int counter_3 = 0; counter_3 < segs[counter_1][counter_2].size(); ++counter_3)
                {
                    volume[counter_2] += abs( segs[counter_1][counter_2][counter_3].first - segs[counter_1][counter_2][counter_3].second );
                }
            }
            
            else
            {
                for (int counter_3 = 0; counter_3 < segs[counter_1][counter_2].size(); ++counter_3)
                {
                    volume[counter_2] += Disk_Segment_Intersection( c, segs[counter_1][counter_2][counter_3] );
                }
            }
        }
    }
    
    for (int counter = 0; counter < input.zone_limit; ++counter)
    {
        volume[counter] = volume[counter] / (double)cell_volume[counter];
    }
    
    for (int counter = 0; counter < input.zone_limit - 1; ++counter)
    {
        results[counter + 1] = volume[counter] - volume[counter + 1];
        
        if (abs( results[counter + 1] ) < tiny_num) results[counter + 1] = tiny_num;
        else if (results[counter + 1] < 0) results[counter + 1] = tiny_num;
    }
    
    if (input.densigram)
    {
        vector<double> vec( 9 );
        
        vec[0] = results[0];
        vec[1] = results[1];
        vec[2] = results[1] + results[2];
        vec[3] = results[1] + results[2] + results[3];
        vec[4] = results[1] + results[2] + results[3] + results[4];
        vec[5] = results[1] + results[2] + results[3] + results[4] + results[5];
        vec[6] = results[1] + results[2] + results[3] + results[4] + results[5] + results[6];
        vec[7] = results[1] + results[2] + results[3] + results[4] + results[5] + results[6] + results[7];
        vec[8] = results[1] + results[2] + results[3] + results[4] + results[5] + results[6] + results[7] + results[8];
        
        for (int counter_2 = 0; counter_2 < input.zone_limit - 1; ++counter_2)
        {
            if (results[counter_2 + 1] > 1 - tiny_num * 1e5) results[counter_2 + 1] = 1 - tiny_num * 1e5;
            
            if (abs( results[counter_2 + 1] ) < tiny_num * 1e5) results[counter_2 + 1] = tiny_num * 1e5;
            else if (results[counter_2 + 1] < 0) results[counter_2 + 1] = tiny_num * 1e5;
        }
        
        results = vec;
    }
}
