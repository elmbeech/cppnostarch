#include "Cell.h"

std::vector<Cell*> all_cells; 

Cell::Cell()
{
	position = {0.0, 0.0}; 
	radius = 5.0; 
	birth_rate = 0.001;
	death_rate = 0.00001; 
	
	mechanics_strength = 0.01; 
	max_interaction_distance = 1.25 * (2*radius); 
	velocity = {0,0}; 

	all_cells.push_back( this ); 
	return; 
}

Cell::Cell( Cell& copy_me )
{
	position = copy_me.position; 
	radius = copy_me.radius; 
	birth_rate = copy_me.birth_rate;  
	death_rate = copy_me.death_rate; 

	mechanics_strength = copy_me.mechanics_strength; 
	max_interaction_distance = copy_me.max_interaction_distance; 
	velocity = {0,0}; 

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

bool Cell::division( void )
{
	// create a new cell 
	Cell* pNewCell; 
	// use the copy constructor 
	pNewCell = new Cell( *this ); 
	
	// place it to the right 
	pNewCell->position[0] += 2.0 * (pNewCell->radius); 
	
	return true; 
}

bool Cell::death( void )
{
	delete this; 
	return true; 
}


long double uniform_random()
{
	// create 64-bit Mersenne twister, seed zero
	// static so it persists between function calls 
	static std::mt19937_64 generator(0); 
	
	// create uniform distribution, static to persist
	// between function calls 
	static std::uniform_real_distribution<> uniform(0.0,1.0);
	return uniform(generator); 
}

bool check_for_birth_and_death( double dt )
{
	Cell* pCell = NULL; 
	
	std::vector<Cell*> birth_list; 
	std::vector<Cell*> death_list; 
	for( int n=0; n < all_cells.size() ; n++ )
	{
		pCell = all_cells[n]; 
		// birth event? 
		if( uniform_random() <= pCell->birth_rate * dt )
		{ birth_list.push_back(pCell); }
		
		// death event? 
		if( uniform_random() <= pCell->death_rate * dt )
		{ death_list.push_back(pCell); }
		n++; 
	}
	// process births
	for( int n=0; n < birth_list.size(); n++ )
	{ birth_list[n]->division(); } 
	
	// process deaths 
	for( int n=0; n < death_list.size(); n++ )
	{ death_list[n]->death(); } 
	
	return true; 
}

void Cell::mechanics_interaction( Cell* pCell )
{
	// don't interact with yourself! 
	if( pCell == this ) 
	{ return; }
	
	// calculate displacement 
	double DisplacementX = pCell->position[0] - position[0]; 
	double DisplacementY = pCell->position[1] - position[1]; 
	
	// calculate distance 
	double distance 
		= sqrt( DisplacementX*DisplacementX + DisplacementY*DisplacementY ); 
	
	// are we in range? 
	if( distance > max_interaction_distance )
	{ return; } 
	
	// normalize displacement (don't divide by zero) 
	distance += 1e-16; 
	DisplacementX /= distance; 
	DisplacementY /= distance; 
	
	// calculate equilibrium spacing 
	double spacing = radius + pCell->radius;
	
	// contribute to velocity 
	double coefficient = mechanics_strength * ( distance-spacing );
	velocity[0] += coefficient * DisplacementX; 
	velocity[1] += coefficient * DisplacementY; 
	return; 
}

void Cell::mechanics_interactions( void )
{
	velocity[0] = 0; 
	velocity[1] = 0; 
	
	for( int n=0 ; n < all_cells.size(); n++ )
	{ mechanics_interaction( all_cells[n] ); }
	
	return; 
}

bool update_mechanics( double dt )
{
	// update velocities 
	
	for( int n=0 ; n < all_cells.size(); n++ )
	{ all_cells[n]->mechanics_interactions(); }

	// update positions 

	for( int n=0 ; n < all_cells.size(); n++ )
	{
		all_cells[n]->position[0] += dt* all_cells[n]->velocity[0]; 
		all_cells[n]->position[1] += dt* all_cells[n]->velocity[1]; 
	}	
	
	return true; 
}
