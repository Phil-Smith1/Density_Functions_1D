#include "Input.h"

void Plot_Graph_File_Names ( Input const& input, string& data_file_1, string& data_file_2, string& graph_file )
{
    if (input.Marjorie_homometric)
    {
        data_file_1 = "Data/Marjorie/" + to_string( input.pt_set ) + ".txt";
        graph_file = "Graphs/Marjorie/" + to_string( input.pt_set ) + ".pdf";
        
        if (input.superimposed)
        {
            data_file_1 = "Data/Marjorie/1.txt";
            data_file_2 = "Data/Marjorie/2.txt";
            graph_file = "Graphs/Marjorie/Sup.pdf";
        }
    }
    
    else if (input.r_homometric)
    {
        data_file_1 = "Data/r_Homometric/" + to_string( input.pt_set ) + ".txt";
        graph_file = "Graphs/r_Homometric/" + to_string( input.pt_set ) + ".pdf";
        
        if (input.superimposed)
        {
            data_file_1 = "Data/r_Homometric/Densigrams/A/0.5.txt";
            data_file_2 = "Data/r_Homometric/Densigrams/Q/0.5.txt";
            graph_file = "Graphs/r_Homometric/Sup.pdf";
        }
    }
    
    else if (input.homometric_13)
    {
        data_file_1 = "Data/Homometric_13/" + to_string( input.pt_set ) + ".txt";
        graph_file = "Graphs/Homometric_13/" + to_string( input.pt_set ) + ".pdf";
        
        if (input.superimposed)
        {
            data_file_1 = "Data/Homometric_13/1.txt";
            data_file_2 = "Data/Homometric_13/2.txt";
            graph_file = "Graphs/Homometric_13/Sup.pdf";
        }
    }
    
    else
    {
        data_file_1 = "Data/Custom.csv";
        graph_file = "Graphs/Custom.pdf";
    }
}
