#include <iostream>
#include <string>
#include <vector>

int main( int argc , char* argv[] )
{
	std::cout << "starting program ..." << std::endl;
	// your code here

    std::vector<double> v( 10 ); // create a vector of doubles of size 10
    for( int i=0 ; i < v.size(); i++ )
    { std::cout << i << " : " << v[i] << std::endl; }
    std::cout << std::endl; 
        
    // add an element to the vector 
    v.push_back( 42.041 ); 
    for( int i=0 ; i < v.size(); i++ )
    { std::cout << i << " : " << v[i] << std::endl; }
    std::cout << std::endl; 
    
    // trim off 3 last elements of the vector 
    v.pop_back();
    v.pop_back(); 
    v.pop_back(); 
    for( int i=0 ; i < v.size(); i++ )
    { std::cout << i << " : " << v[i] << std::endl; }
    std::cout << std::endl; 

	std::cout << "done!" << std::endl; 
	return 0;
}
