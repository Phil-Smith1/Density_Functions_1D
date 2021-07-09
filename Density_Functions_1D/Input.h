#pragma once

#include <string>
#include <vector>

using namespace std;

class Input
{
    public:
    
    bool Marjorie_homometric, r_homometric, homometric_13, use_threads, replot, title, superimposed, densigram, zero_df;
    int pt_set, zone_limit, perim, sample_rate;
    double r, cell_param, max_radius;
    string output_dir, title_str;
    vector<double> frac_base_pts;
    
    Input ( bool M_h, int p_s, bool r_h, double r_p, bool h_13, double c_p, int z_l, int p, int s_r, bool u_t, string const& o_d, bool t, string const& t_s, bool re, bool s, bool d, bool z_d );
    
    Input();
    ~Input();
};
