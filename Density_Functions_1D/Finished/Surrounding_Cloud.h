#pragma once

#include <vector>
#include <map>
#include <cmath>

using namespace std;

void Surrounding_Cloud ( double cell_param, int perim, int index, vector<double>const& base_pts, multimap<double, double>& cloud );
