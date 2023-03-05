#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <random> 
#include <cmath>

#include "Cell.h" 
#include "save.h" 
#include "environment.h" 

std::string version = "v6"; 

int main( int argc, char* argv[] )
{
	std::cout << "starting version " << version << " ... " << std::endl;
	
	// parse settings 
	
	// create cell types 
	
	// create environment 
	
	environment.set_domain( {-140.0,140.0,-140.0,140.0} ); 
	environment.set_shape( {15,15} ); 
	for( int j = 0 ; j < environment.shape[1] ; j++ )
	{
		for( int i = 0 ; i < environment.shape[0] ; i++ )
		{
			double r2 = pow( environment.X[i] , 2 ) + pow( environment.Y[j] , 2 ) ; 
			environment(i,j) = 1.0 - 0.8 * exp( -r2 / 3600.0 );  
		}
	}
	
	// place cells 
	int number_of_cells = 50; 
	Cell* pCell;
	// random positions 
	for( int n=0; n < number_of_cells ; n++ )
	{
		pCell = new Cell; 
		pCell->position[0] = -50 + 100*uniform_random(); 
		pCell->position[1] = -50 + 100*uniform_random(); 
	}

	long double t = 0; 
	double max_time =  5 * 24 * 60; 
	double output_interval = 30; 
	
	double next_output_time = 0.0; 
	double dt = 0.05; // 0.1 
	while( t < max_time + 0.01*dt )
	{
		// output? 
		if( fabs(t-next_output_time) < 0.01*dt )
		{
			std::cout << t << " of " << max_time << " (min)" << std::endl; 
			std::cout << "\tCell count: " << all_cells.size() << std::endl; 
			
			save_data(); 
			
			next_output_time += output_interval; 
		}
		
		// update environment 
		
		// update phenotypes
		
		update_phenotypes( dt ); 
		
		// birth and death 
		check_for_birth_and_death( dt ); 
		
		// update positions 
		update_mechanics( dt ); 
		
		t += dt; 
	}
	
	std::cout << "done!"  << std::endl;
	
	return 0; 
}
