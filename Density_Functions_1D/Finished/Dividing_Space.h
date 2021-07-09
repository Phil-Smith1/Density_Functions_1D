#pragma once

#include "Divide_Segment.h"

#include <thread>

void Dividing_Space ( multimap<double, double>const& cloud, double base_pt, int zone_limit, vector<Seg>& final_segs, vector<double>& max_radii, bool use_threads );
