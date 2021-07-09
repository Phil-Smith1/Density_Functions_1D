#pragma once

#include "Seg.h"

#include <vector>

using namespace std;

#ifndef tiny_number
#define tiny_number
const double tiny_num = 1e-10;
#endif

void Removing_Segments ( double const& base_pt, double distance, vector<Seg>& segs, vector<Seg>& final_segs, int zone_limit );
