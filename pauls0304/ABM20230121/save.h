#ifndef __save_h_ 
#define __save_h_

#include <vector>
#include <random> 
#include <ctime>

#include <fstream>
#include <string>
#include <iostream>

#include "Cell.h" 

std::string output_filename( void );
bool output( std::string filename ); 
bool save_data( void ); 

#endif
