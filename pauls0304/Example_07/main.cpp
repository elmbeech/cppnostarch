#include <iostream>
#include <string>
#include <vector>

void display_vector( std::vector<double>& v )
{
	for( int i=0; i < v.size(); i++ )
	{ std::cout << i << ": " << v[i] << std::endl; }
	std::cout << std::endl; 
}

std::vector<double> operator+( std::vector<double>& v, std::vector<double>& w )
{
	unsigned int m = v.size(); 
	if( w.size() < m )
	{ m = w.size(); }
	std::vector<double> z( m ); 
	for( unsigned int i=0; i < m ; i++ )
	{ z[i] = v[i] + w[i]; }
	return z;
}

int main( int argc , char* argv[] )
{
	std::cout << "starting program ..." << std::endl; // your code here

	std::vector<double> v = { 0.0, 1.0 , 2.0 }; // handy way to start!
	display_vector( v ); 

	for( unsigned int i=0 ; i < v.size(); i++ ) // act on elements of v
    { v[i] = i; }
	display_vector( v ) ; 
	
	std::vector<double> w = v; // copy v to w
	for( unsigned int i=0 ; i < w.size(); i++ ) // act on elements of w
    { w[i] = i*i; }
	display_vector( w ) ; 
	
	std::vector<double> z = v + w; // add v and w 
	display_vector( z ); 

	z.clear(); // clear z 
	display_vector( z ); 

	std::cout << "done!" << std::endl; 
	return 0;
}
