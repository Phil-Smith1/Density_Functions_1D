#pragma once

#include <utility>
#include <cmath>

using namespace std;

#ifndef tiny_number
#define tiny_number
const double tiny_num = 1e-10;
#endif

double Disk_Segment_Intersection ( pair<double, double>const& c, pair<double, double>const& seg );
