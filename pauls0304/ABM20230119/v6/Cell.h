#ifndef __Cell_h__
#define __Cell_h__

#include <vector>
#include <random> 
#include <ctime>

#include <fstream>
#include <string>
#include <iostream>

#include "Environment.h" 

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
		
		void (*mechanics_interaction)( Cell* pMe, Cell* pOther ); 
		void mechanics_interactions( void );  
		
		void (*phenotype_model)( Cell* pMe, double dt ); 
		void update_phenotype( double dt ); 
		
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
bool update_phenotypes( double dt ); 

void spring_mechanics( Cell* pMe, Cell* pOther ); 
void simple_phenotype( Cell* pMe , double dt ); 

#endif 
