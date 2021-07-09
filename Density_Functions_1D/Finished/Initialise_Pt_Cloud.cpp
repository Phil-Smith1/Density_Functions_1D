#include "Input.h"
#include "Surrounding_Cloud.h"

void Initialise_Pt_Cloud ( Input const& input, vector<multimap<double, double>>& clouds, vector<double>& base_pts )
{
    for (int counter = 0; counter < input.frac_base_pts.size(); ++counter)
    {
        base_pts.push_back( input.frac_base_pts[counter] );
        base_pts[counter] *= input.cell_param;
    }

    clouds.resize( base_pts.size() );

    for (int counter = 0; counter < base_pts.size(); ++counter)
    {
        Surrounding_Cloud( input.cell_param, input.perim, counter, base_pts, clouds[counter] );
    }
}
