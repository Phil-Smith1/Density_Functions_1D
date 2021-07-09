#include "Input.h"

void Data_File_Name ( Input const& input, string& data_file )
{
    if (input.Marjorie_homometric)
    {
        data_file = input.output_dir + "Data/Marjorie/" + to_string( input.pt_set ) + ".txt";
    }
    
    else if (input.r_homometric)
    {
        data_file = input.output_dir + "Data/r_Homometric/" + to_string( input.pt_set ) + ".txt";
    }
    
    else if (input.homometric_13)
    {
        data_file = input.output_dir + "Data/Homometric_13/" + to_string( input.pt_set ) + ".txt";
    }
    
    else data_file = input.output_dir + "Data/Custom.csv";
}
