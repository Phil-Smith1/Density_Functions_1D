#pragma once

#include "Dividing_Space.h"

void Compute_Brillouin_Zones ( multimap<double, double>const& cloud, double base_pt, int zone_limit, vector<vector<pair<double, double>>>& segs, vector<double>& max_radii, vector<double>& cell_volume, bool use_threads );
