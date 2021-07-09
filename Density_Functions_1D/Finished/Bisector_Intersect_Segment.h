#pragma once

#include <utility>

using namespace std;

#ifndef tiny_number
#define tiny_number
const double tiny_num = 1e-10;
#endif

int Bisector_Intersect_Segment ( pair<double, double>const& seg, double base_pt, double bisector );
