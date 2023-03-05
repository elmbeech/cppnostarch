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

    std::vector<double> v( 10 ); // create a vector of doubles of size 10
	display_vector( v ); 

    for( int i=0 ; i < v.size(); i++ ) // act on elements of v
    { v[i] = i; }
	display_vector( v ) ; 
        
    // add an element to the vector 
    v.push_back( 42.041 ); 
	display_vector( v ) ; 
    
    // trim off 3 last elements of the vector 
    v.pop_back();
    v.pop_back(); 
    v.pop_back(); 
	display_vector( v ) ; 

	std::cout << "done!" << std::endl; 
	return 0;
}
