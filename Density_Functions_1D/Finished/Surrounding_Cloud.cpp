#include <vector>
#include <map>
#include <cmath>

using namespace std;

void Surrounding_Cloud ( double cell_param, int perim, int index, vector<double>const& base_pts, multimap<double, double>& cloud )
{
    for (int counter_1 = -perim; counter_1 < perim + 1; ++counter_1)
    {
        double v = counter_1 * cell_param;
        
        for (int counter_2 = 0; counter_2 < base_pts.size(); ++counter_2)
        {
            if (counter_1 == 0 && counter_2 == index) continue;
            
            double p = base_pts[counter_2] + v;
            
            double dist = abs( p - base_pts[index] );
            
            cloud.insert( pair<double, double>( dist, p ) );
        }
    }
}
