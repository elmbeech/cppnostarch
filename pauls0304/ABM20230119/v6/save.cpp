#include "save.h" 

std::string output_filename( void )
{
	static int output_index = 0; 
	
	static std::string output_directory = "./data"; 
	
	char temp [1024]; 
	sprintf( temp , "%s/output%08u.csv" , output_directory.c_str() , output_index ); 
	output_index++; 
	
	std::string output = temp;
	return output; 	
}

bool output( std::string filename )
{
	std::cout << "\tSaving data to " << filename << " ... "; 
	
	std::ofstream out( filename , std::ofstream::out ); 
	
	// first row: number of cells
	out << all_cells.size() << std::endl; 
	
	// next rows: cells 
	// x,y,radius,vx,vy,birth,death,mechanics,
	
	for( int n=0 ; n < all_cells.size() ; n++ )
	{
		Cell* pC = all_cells[n]; 
		out << pC->position[0] << "," << pC->position[1] << "," 
			<< pC->radius << "," 
			<< pC->velocity[0] << "," << pC->velocity[1] << "," 
			<< pC->birth_rate << "," << pC->death_rate << "," 
			<< pC->mechanics_strength << std::endl; 
	}
	
	// next row: X values 
	for( int n=0; n < environment.X.size()-1 ; n++ )
	{ out << environment.X[n] << ","; }
	out << environment.X.back() << std::endl; 
	
	// next row: Y values 
	for( int n=0; n < environment.Y.size()-1 ; n++ )
	{ out << environment.Y[n] << ","; }
	out << environment.Y.back() << std::endl; 
	
	// next row: all data values 
	for( int n=0; n < environment.substrate.size()-1 ; n++ )
	{ out << environment[n] << ","; }
	out << environment.substrate.back() << std::endl; 
	
	out.close(); 
	
	std::cout << " done!" << std::endl; 
	
	return true; 
}

bool save_data( void )
{
	std::string filename = output_filename(); 
	return output( filename ); 
}
