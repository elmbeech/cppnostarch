#include "Cell.h"

std::vector<Cell*> all_cells; 

Cell::Cell()
{
	position = {0.0 , 0.0}; 
	radius = 5.0; 
	birth_rate = 0.001; 
	death_rate = 0.00001; 
	adhesion_strength = 0.1; 
	max_interaction_distance = 1.5 * radius; 

	all_cells.push_back( this ); 
	return; 
}

Cell::Cell( Cell& copy_me )
{
	position = copy_me.position; 
	radius = copy_me.radius; 
	birth_rate = copy_me.birth_rate;  
	death_rate = copy_me.death_rate; 
	adhesion_strength = copy_me.adhesion_strength; 
	max_interaction_distance = copy_me.max_interaction_distance; 

	all_cells.push_back( this ); 
	return; 
}

Cell::~Cell()
{
	// find and remove self 
	int n = 0; 
	bool done = false;
	while( done == false )
	{
		if( all_cells[n] == this )
		{
			all_cells[n] = all_cells.back(); 
			all_cells.pop_back(); 
			done = true; 
		}
		n++; 
	}
	return; 
}
