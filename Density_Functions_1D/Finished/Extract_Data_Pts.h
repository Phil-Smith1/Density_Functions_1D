#pragma once

#include "Data_Pts_For_Given_Radius.h"
#include "Data_File_Name.h"

#include <fstream>
#include <thread>

void Extract_Data_Pts ( Input& input, vector<double>const& base_pts, vector<vector<vector<pair<double, double>>>> segs, vector<double>const& cell_volume, vector<vector<double>>const& max_radii );
