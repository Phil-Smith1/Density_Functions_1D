#pragma once

#include "Max_Distance_To_Segment.h"
#include "Removing_Segments.h"
#include "Bisector_Intersect_Segment.h"
#include "Max_Radius_Of_Space.h"

#include <map>
#include <mutex>

void Divide_Segment ( multimap<double, double>const cloud, double base_pt, int zone_limit, pair<double, double> seg, int starting_zone, vector<Seg>& final_segs );
