#include "Input.h"

void Initialise_Parameters( Input& input )
{
    if (input.Marjorie_homometric)
    {
        if (input.pt_set == 1)
        {
            input.cell_param = 1;
            input.frac_base_pts.push_back( 0 );
            input.frac_base_pts.push_back( 3 / (double)8 );
            input.frac_base_pts.push_back( 0.5 );
            input.frac_base_pts.push_back( 5 / (double)8 );
        }
        
        if (input.pt_set == 2)
        {
            input.cell_param = 1;
            input.frac_base_pts.push_back( 1 / (double)8 );
            input.frac_base_pts.push_back( 0.25 );
            input.frac_base_pts.push_back( 0.75 );
            input.frac_base_pts.push_back( 7 / (double)8 );
        }
    }
    
    else if (input.r_homometric)
    {
        if (input.pt_set == 1)
        {
            input.cell_param = 8;
            input.frac_base_pts.push_back( 0 );
            input.frac_base_pts.push_back( input.r / (double)8 );
            input.frac_base_pts.push_back( (input.r + 2) / (double)8 );
            input.frac_base_pts.push_back( 4 / (double)8 );
        }
        
        if (input.pt_set == 2)
        {
            input.cell_param = 8;
            input.frac_base_pts.push_back( 0 );
            input.frac_base_pts.push_back( (input.r + 2) / (double)8 );
            input.frac_base_pts.push_back( 4 / (double)8 );
            input.frac_base_pts.push_back( (input.r + 4) / (double)8 );
        }
    }
    
    else if (input.homometric_13)
    {
        if (input.pt_set == 1)
        {
            input.cell_param = 13;
            input.frac_base_pts.push_back( 0 );
            input.frac_base_pts.push_back( 1 / (double)13 );
            input.frac_base_pts.push_back( 4 / (double)13 );
            input.frac_base_pts.push_back( 6 / (double)13 );
        }
        
        if (input.pt_set == 2)
        {
            input.cell_param = 13;
            input.frac_base_pts.push_back( 0 );
            input.frac_base_pts.push_back( 2 / (double)13 );
            input.frac_base_pts.push_back( 3 / (double)13 );
            input.frac_base_pts.push_back( 7 / (double)13 );
        }
    }

    else
    {
        if (input.pt_set == 1)
        {
            input.cell_param = 15;
            input.frac_base_pts.push_back( 0 );
            input.frac_base_pts.push_back( 1 / (double)input.cell_param );
            input.frac_base_pts.push_back( 3 / (double)input.cell_param );
            input.frac_base_pts.push_back( 4 / (double)input.cell_param );
            input.frac_base_pts.push_back( 5 / (double)input.cell_param );
            input.frac_base_pts.push_back( 7 / (double)input.cell_param );
            input.frac_base_pts.push_back( 9 / (double)input.cell_param );
            input.frac_base_pts.push_back( 10 / (double)input.cell_param );
            input.frac_base_pts.push_back( 12 / (double)input.cell_param );
        }
        
        if (input.pt_set == 2)
        {
            input.cell_param = 15;
            input.frac_base_pts.push_back( 0 );
            input.frac_base_pts.push_back( 2 / (double)input.cell_param );
            input.frac_base_pts.push_back( 3 / (double)input.cell_param );
            input.frac_base_pts.push_back( 4 / (double)input.cell_param );
            input.frac_base_pts.push_back( 6 / (double)input.cell_param );
            input.frac_base_pts.push_back( 7 / (double)input.cell_param );
            input.frac_base_pts.push_back( 9 / (double)input.cell_param );
            input.frac_base_pts.push_back( 11 / (double)input.cell_param );
            input.frac_base_pts.push_back( 12 / (double)input.cell_param );
        }
    }
}
