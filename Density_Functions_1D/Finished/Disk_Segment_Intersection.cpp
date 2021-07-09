#include <utility>
#include <cmath>

using namespace std;

#ifndef tiny_number
#define tiny_number
const double tiny_num = 1e-10;
#endif

double Disk_Segment_Intersection ( pair<double, double>const& c, pair<double, double>const& seg )
{
    if (c.first < seg.first + tiny_num && c.second > seg.second - tiny_num) return abs( seg.first - seg.second );
    
    if (c.second < seg.first + tiny_num) return 0;
    
    if (c.first > seg.second - tiny_num) return 0;
    
    if (seg.first < c.first + tiny_num && seg.second > c.second - tiny_num) return abs( c.first - c.second );
    
    if (c.first < seg.first + tiny_num && c.second > seg.first - tiny_num) return abs( c.second - seg.first );
    
    else return abs( c.first - seg.second );
}
