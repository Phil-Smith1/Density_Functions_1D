#include "Parameters.h"
#include "Initialise_Parameters.h"
#include "Initialise_Pt_Cloud.h"
#include "Compute_Brillouin_Zones.h"
#include "Extract_Data_Pts.h"
#include "Plot_Graph.h"
#include "Print_Info.h"

int main( int, char*[] )
{
    clock_t start_code_runtime = clock(); // Starts the clock measuring the runtime of the code.
    
    chrono::time_point<chrono::steady_clock> start_absolute_time = chrono::steady_clock::now(); // Starts the clock measuring the absolute time to complete the code.
    
    Initialise_Parameters( input );
    
    if (!input.replot)
    {
        vector<double> base_pts;
        vector<multimap<double, double>> clouds;
        
        Initialise_Pt_Cloud( input, clouds, base_pts );
        
        cout << "Computing Brillouin zones for " << base_pts.size() << " points." << endl;
        
        vector<vector<vector<pair<double, double>>>> segs( (int)base_pts.size() );
        vector<vector<double>> max_radii( (int)base_pts.size() );
        vector<double> cell_volume( input.zone_limit, 0 );
        
        if (input.use_threads)
        {
            vector<thread> thr;
            
            for (int counter = 0; counter < base_pts.size(); ++counter)
            {
                thr.push_back( thread( Compute_Brillouin_Zones, clouds[counter], base_pts[counter], input.zone_limit, ref( segs[counter] ), ref( max_radii[counter] ), ref( cell_volume ), true ) );
            }
            
            for (int counter = 0; counter < base_pts.size(); ++counter)
            {
                thr[counter].join();
            }
        }
        
        else
        {
            for (int counter = 0; counter < base_pts.size(); ++counter)
            {
                Compute_Brillouin_Zones( clouds[counter], base_pts[counter], input.zone_limit, segs[counter], max_radii[counter], ref( cell_volume ), false );
            }
        }
        
        cout << "Brillouin zones computed." << endl;
        
        Extract_Data_Pts( input, base_pts, segs, cell_volume, max_radii );
        
        cout << "Data extracted." << endl;
    }
    
    Plot_Graph( input );
    
    cout << "Graph plotted." << endl << endl;
    
    Print_Info( start_code_runtime, start_absolute_time );
    
    return 0;
}
