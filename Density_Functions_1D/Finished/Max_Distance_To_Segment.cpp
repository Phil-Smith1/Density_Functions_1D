#include <cmath>

double Max_Distance_To_Segment ( double base_pt, double left, double right )
{
    double max_radius = 0;
    
    double dist1 = abs( base_pt - left );
    double dist2 = abs( base_pt - right );
    
    if (dist1 > max_radius) max_radius = dist1;
    if (dist2 > max_radius) max_radius = dist2;
    
    return max_radius;
}
