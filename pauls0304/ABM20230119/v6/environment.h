#ifndef __environment_h__
#define __environment_h__

#include <cstdio>
#include <vector> 
#include <iostream>
#include <cmath>

#include "Cell.h" 

std::ostream& operator<<( std::ostream& os , const std::vector<int>& vec );
std::ostream& operator<<( std::ostream& os , const std::vector<double>& vec );

class Environment
{
 private:
 public:
	std::vector<int> shape; 
	std::vector<double> X; 
	std::vector<double> Y; 
	double dx;
	double dy; 
	std::vector<double> substrate; 
	double diffusion_coefficient; 
	double decay_rate; 
	
	Environment();
	~Environment(); 
	
	double& operator()( double x, double y ); 
	double& operator()( int i, int j ); 
	double& operator[]( int k); 
	
	int get_index( double x , double y ); 
	int get_index( int i, int j ); 
	
	bool set_domain(double xL, double xR, double yD, double yU ); 
	bool set_domain( std::vector<double> bounds ); 
	bool set_shape( std::vector<int> shape ); 
	
	double stability_dt_bound( void ); 
	double suggest_dt( void ); 
};

extern Environment environment; 

#endif
