#pragma once

#include "Input.h"
#include "Disk_Segment_Intersection.h"

void Data_Pts_For_Given_Radius ( Input const input, int sample, vector<double>const base_pts, vector<vector<vector<pair<double, double>>>>const segs, vector<double>const cell_volume, vector<vector<double>>const max_radii, vector<double>& results );
