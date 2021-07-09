#include "Data_Pts_For_Given_Radius.h"
#include "Data_File_Name.h"

#include <fstream>
#include <thread>

void Extract_Data_Pts ( Input& input, vector<double>const& base_pts, vector<vector<vector<pair<double, double>>>> segs, vector<double>const& cell_volume, vector<vector<double>>const& max_radii )
{
    double max_radius = 0;
    
    for (int counter = 0; counter < base_pts.size(); ++counter)
    {
        double rad = max_radii[counter][max_radii[counter].size() - 1];
        
        if (rad > max_radius) max_radius = rad;
    }
    
    int num_pts = max_radius * input.sample_rate + 1;
    
    input.max_radius = (num_pts - 1) / (double)input.sample_rate;
    
    if (num_pts < max_radius * input.sample_rate + 1)
    {
        ++num_pts;
        input.max_radius = (num_pts - 1) / (double)input.sample_rate;
    }
    
    vector<vector<double>> results( num_pts );
    
    if (input.use_threads)
    {
        vector<thread> thr;
        
        for (int counter = 0; counter < num_pts; ++counter)
        {
            results[counter].resize( input.zone_limit + 1 );
            thr.push_back( thread( Data_Pts_For_Given_Radius, input, counter, base_pts, segs, cell_volume, max_radii, ref( results[counter] ) ) );
        }
        
        for (int counter = 0; counter < num_pts; ++counter)
        {
            thr[counter].join();
        }
    }
    
    else
    {
        for (int counter = 0; counter < num_pts; ++counter)
        {
            results[counter].resize( input.zone_limit + 1 );
            
            Data_Pts_For_Given_Radius( input, counter, base_pts, segs, cell_volume, max_radii, results[counter] );
        }
    }
    
    // Adding 0th density function
    
    if (input.zero_df)
    {
        bool df0_is_0 = false;
        
        for (int counter_1 = 0; counter_1 < results.size(); ++counter_1)
        {
            for (int counter_2 = input.zone_limit; counter_2 > 1; --counter_2)
            {
                results[counter_1][counter_2] = results[counter_1][counter_2 - 1];
            }
            
            if (df0_is_0) results[counter_1][1] = tiny_num;
            
            else
            {
                results[counter_1][1] = 1;
                
                for (int counter_2 = 2; counter_2 < input.zone_limit + 1; ++counter_2)
                {
                    results[counter_1][1] -= results[counter_1][counter_2];
                }
                
                //results[counter_1][1] = 1 - at_least_1[counter_1];
            }
            
            if (results[counter_1][1] < tiny_num * 1e4) df0_is_0 = true;
        }
    }
    
    string data_file;
    
    Data_File_Name( input, data_file );
    
    int z_l = input.zone_limit;
    
    if (!input.zero_df) --z_l;
    
    ofstream ofs( data_file );
    
    ofs << setprecision( 10 ) << results[0][0];
    
    for (int counter = 0; counter < z_l; ++counter)
    {
        ofs << "," << results[0][counter + 1];
    }
    
    for (int counter_1 = 1; counter_1 < num_pts; ++counter_1)
    {
        ofs << endl;
        
        ofs << setprecision( 10 ) << results[counter_1][0];
        
        for (int counter_2 = 0; counter_2 < z_l; ++counter_2)
        {
            ofs << "," << results[counter_1][counter_2 + 1];
        }
    }
    
    ofs.close();
}
