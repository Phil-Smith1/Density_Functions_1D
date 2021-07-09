#include "Input.h"

Input::Input ( bool M_h, int p_s, bool r_h, double r_p, bool h_13, double c_p, int z_l, int p, int s_r, bool u_t, string const& o_d, bool t, string const& t_s, bool re, bool s, bool d, bool z_d )
{
    Marjorie_homometric = M_h;
    pt_set = p_s;
    r_homometric = r_h;
    r = r_p;
    homometric_13 = h_13;
    cell_param = c_p;
    zone_limit = z_l;
    perim = p;
    sample_rate = s_r;
    use_threads = u_t;
    output_dir = o_d;
    title = t;
    title_str = t_s;
    replot = re;
    superimposed = s;
    densigram = d;
    zero_df = z_d;
}

Input::Input(){}
Input::~Input(){}
