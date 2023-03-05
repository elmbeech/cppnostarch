#include <iostream>
#include <string>
#include <vector>

void display_vector( std::vector<double>& v )
{
	for( int i=0; i < v.size(); i++ )
	{ std::cout << i << ": " << v[i] << std::endl; }
	std::cout << std::endl; 
}

int main( int argc , char* argv[] )
{
	std::cout << "starting program ..." << std::endl;
	// your code here

    std::vector<double> v( 10 , 3.0 ); // create a vector of doubles of size 10, initialized to 3.0 
	display_vector( v ); 

	v.resize( 3 ); // shrink or grow to size 3. 
	display_vector( v ); 

	v.resize( 12 ); // shrink or grow to size 12. 
	display_vector( v ); 

    for( int i=0 ; i < v.size(); i++ ) // act on elements of v
    { v[i] = i; }
	display_vector( v ) ;        

	std::cout << "done!" << std::endl; 
	return 0;
}