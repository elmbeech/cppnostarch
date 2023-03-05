#include "environment.h"

std::ostream& operator<<( std::ostream& os , const std::vector<int>& vec )
{
	for( int n=0; n < vec.size()-1 ; n++ )
	{ os << vec[n] << "," ; }
	os << vec.back(); 
	return os; 
}

std::ostream& operator<<( std::ostream& os , const std::vector<double>& vec )
{
	for( int n=0; n < vec.size()-1 ; n++ )
	{ os << vec[n] << "," ; }
	os << vec.back(); 
	return os; 
}

Environment::Environment()
{
	shape = {2,2}; 

	X.resize( shape[0] ); 
	Y.resize( shape[1] ); 
	X[0] = 0; X[1] = 1; 
	Y[0] = 0; Y[1] = 1;
	dx = X[1]-X[0]; 
	dy = Y[1]-Y[0]; 

	substrate.resize( shape[0]*shape[1] ); 
	
	// length scale = 100, 50% decay < 10 min, 90% decay < 52 min 
	diffusion_coefficient = 1000; 
	decay_rate = 0.01* 0.1; 
	
	return; 
}

Environment::~Environment()
{ return; } 

bool Environment::set_domain(double xL, double xR, double yD, double yU )
{
	int m = shape[0];
	dx = (xR-xL)/(m-1.0); 
	for( int k=0 ; k<m ; k++ )
	{ X[k] = xL + dx*k; } 
	
	int n = shape[1];
	dy = (yU-yD)/(n-1.0); 
	for( int k=0 ; k<n ; k++ )
	{ Y[k] = yD + dy*k; } 
	
	return true; 
}

bool Environment::set_domain( std::vector<double> bounds )
{ return set_domain( bounds[0] , bounds[1] , bounds[2] , bounds[3] ); } 

bool Environment::set_shape( std::vector<int> shape_in )
{
	double xL = X.front(); 
	double xR = X.back();
	int m = shape_in[0]; 
	X.resize( m ); 
	
	dx = (xR-xL)/(m-1.0); 
	for( int k=0 ; k<m ; k++ )
	{ X[k] = xL + dx*k; } 
	
	double yD = Y.front(); 
	double yU = Y.back(); 
	int n = shape_in[1]; 
	Y.resize( n ); 
	dy = (yU-yD)/(n-1.0); 
	for( int k=0 ; k<n ; k++ )
	{ Y[k] = yD + dy*k; } 	
	
	shape = shape_in; 
	
	substrate.resize( shape[0] * shape[1] );
	
	return true;
}


double& Environment::operator()( double x , double y )
{
	// find nearest i
	int i = (int) floor( (x-X.front())/dx ); 
	// find nearest j 
	int j = (int) floor( (y-Y.front())/dy );
	// use operator()(int,int) 
	return (*this)(i,j); 
}

double& Environment::operator()( int i, int j )
{
	// use operator[n] using the ordering n = j*shape[0] + i; 
	return (*this)[j*shape[0]+i]; 
} 

double& Environment::operator[](int k)
{ return substrate[k]; } 

int Environment::get_index( double x, double y )
{
	// find nearest i
	int i = (int) floor( (x-X.front())/dx ); 
	// find nearest j 
	int j = (int) floor( (y-Y.front())/dy );
	// use operator()(int,int) 
	return j*shape[0] + i; 
}

int Environment::get_index( int i, int j )
{ return j*shape[0] + i; } 

double Environment::stability_dt_bound( void )
{
	double dx2 = dx*dx; 
	double dy2 = dy*dy; 
	double temp = 1.0/dx2 + 1.0/dy2; 
	
	return (1.0/(2.0*temp*diffusion_coefficient));
}

double Environment::suggest_dt( void )
{
	double dt_bound = stability_dt_bound(); 

	// get nearest power of 2 
	int nearest_power = (int) ceil( -log(dt_bound)/log(2.0) ); 
	return pow( 2.0 , -nearest_power );
}

Environment environment; 
