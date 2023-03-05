#ifndef __Cell_h__
#define __Cell_h__

#include <vector>
#include <random> 
#include <ctime>

#include <fstream>
#include <string>
#include <iostream>

class Cell
{
	private:
	public: 
		std::vector<double> position; 
		double radius; 
		double birth_rate; 
		double death_rate; 
		
		std::vector<double> velocity; 
		double mechanics_strength; 
		double max_interaction_distance; 
		void mechanics_interaction( Cell* pCell ); 
		void mechanics_interactions( void );  
		
		Cell();
		Cell( Cell& copy_me ); 
		~Cell(); 
		bool division( void ); 
		bool death( void ); 
		bool movement( double dt ); 
};

extern std::vector<Cell*> all_cells;

long double uniform_random( void ); 

bool check_for_birth_and_death( double dt );
bool update_mechanics( double dt ); 

#endif 
