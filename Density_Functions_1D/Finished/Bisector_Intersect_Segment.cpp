#include <utility>

using namespace std;

#ifndef tiny_number
#define tiny_number
const double tiny_num = 1e-10;
#endif

int Bisector_Intersect_Segment ( pair<double, double>const& seg, double base_pt, double bisector )
{
    if (bisector < seg.first + tiny_num || bisector > seg.second - tiny_num)
    {
        if (base_pt < bisector && bisector < seg.first + tiny_num) return -1;
        
        else if (base_pt > bisector && bisector > seg.second - tiny_num) return -1;
        
        else return 1;
    }
    
    else return 0;
}
