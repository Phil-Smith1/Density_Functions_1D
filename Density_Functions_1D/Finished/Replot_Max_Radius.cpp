#include <fstream>
#include <sstream>

#include "Input.h"

void Replot_Max_Radius ( Input& input, string const& data_file_1, string const& data_file_2 )
{
    ifstream ifs_1( input.output_dir + data_file_1 );
    string line_data;
    
    double max_radius = 0;
    
    while (getline( ifs_1, line_data ))
    {
        stringstream stream;
        
        stream << line_data;
        
        stream >> max_radius;
    }
    
    input.max_radius = max_radius;
    
    ifs_1.close();
    
    if (input.superimposed)
    {
        ifstream ifs_2( input.output_dir + data_file_2 );
        string line_data;
        
        max_radius = 0;
        
        while (getline( ifs_2, line_data ))
        {
            stringstream stream;
            
            stream << line_data;
            
            stream >> max_radius;
        }
        
        if (input.max_radius < max_radius) input.max_radius = max_radius;
        
        ifs_2.close();
    }
}
