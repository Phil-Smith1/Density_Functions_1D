#pragma once

#include "Input.h"

bool Marjorie_homometric = false;

bool r_homometric = false;

double r = 1.5;

bool homometric_13 = false;

int pt_set = 1;

double cell_param = 1;

int zone_limit = 19;

int perim = 10;

int sample_rate = 10;

bool use_threads = false;

string output_dir = "/Users/philsmith/Documents/Work/Xcode Projects/Density_Functions_1D/Output/";

bool title = false;

string title_str = "Density Functions";

bool replot = false;

bool superimposed = false;

bool densigram = false;

bool zero_df = true;

Input input( Marjorie_homometric, pt_set, r_homometric, r, homometric_13, cell_param, zone_limit, perim, sample_rate, use_threads, output_dir, title, title_str, replot, superimposed, densigram, zero_df );
