#include <iostream>
#include <string>
#include <cstdlib>
#include <random>

int main( int argc , char* argv[] )
{
	std::cout << "starting program ..." << std::endl; 
	// your code here
	
	std::mt19937_64 generator( 0 ); 
	// initialize 64-bit Mersenne twister with seed 0
	
	std::uniform_real_distribution<> uniform(0.0,1.0);
	std::cout << "uniform:" << std::endl; 
	for (int n = 0; n < 10; n++)
	{
		// use uniform() to transform a random number 
		// from generator to a number in U(0,1).
		std::cout << uniform(generator) << ' ';
	}
	std::cout << std::endl << std::endl; 
	
	std::normal_distribution<> normal(0.0,1.0);
	std::cout << "normal:" << std::endl; 
	for (int n = 0; n < 10; n++ ) 
	{
		// use uniform() to transform a random number 
		// from generator to a number in N(0,1).
		std::cout << normal(generator) << ' ';
	}
	std::cout << std::endl << std::endl;
	
    double probability = 0.15; 
	int number_of_tests = 100000; 
	int number_of_events = 0; 

	std::cout << "getting random events:" << std::endl; 
	for (int n = 0; n < number_of_tests; n++)
	{
		if( uniform(generator) <= probability )
		{ number_of_events++; } 
	}
    
	double fraction = (double) number_of_events 
		/ (double) number_of_tests; 
	std::cout << "fraction of events: " << fraction 
		<< " vs " << probability << std::endl << std::endl; 
	
	std::cout << "done!" << std::endl; 
	return 0;
}

/*

https://cpp.sh/?source=%23include+%3Ciostream%3E%0D%0A%23include+%3Cstring%3E%0D%0A%23include+%3Ccstdlib%3E%0D%0A%23include+%3Crandom%3E%0D%0A%0D%0Aint+main(+int+argc+%2C+char*+argv%5B%5D+)%0D%0A%7B%0D%0A%09std%3A%3Acout+%3C%3C+%22starting+program+...%22+%3C%3C+std%3A%3Aendl%3B+%0D%0A%09%2F%2F+your+code+here%0D%0A%09%0D%0A%09std%3A%3Amt19937_64+generator(+0+)%3B+%0D%0A%09%2F%2F+initialize+64-bit+Mersenne+twister+with+seed+0%0D%0A%09%0D%0A%09std%3A%3Auniform_real_distribution%3C%3E+uniform(0.0%2C1.0)%3B%0D%0A%09std%3A%3Acout+%3C%3C+%22uniform%3A%22+%3C%3C+std%3A%3Aendl%3B+%0D%0A%09for+(int+n+%3D+0%3B+n+%3C+10%3B+n%2B%2B)%0D%0A%09%7B%0D%0A%09%09%2F%2F+use+uniform()+to+transform+a+random+number+%0D%0A%09%09%2F%2F+from+generator+to+a+number+in+U(0%2C1).%0D%0A%09%09std%3A%3Acout+%3C%3C+uniform(generator)+%3C%3C+%27+%27%3B%0D%0A%09%7D%0D%0A%09std%3A%3Acout+%3C%3C+std%3A%3Aendl+%3C%3C+std%3A%3Aendl%3B+%0D%0A%09%0D%0A%09std%3A%3Anormal_distribution%3C%3E+normal(0.0%2C1.0)%3B%0D%0A%09std%3A%3Acout+%3C%3C+%22normal%3A%22+%3C%3C+std%3A%3Aendl%3B+%0D%0A%09for+(int+n+%3D+0%3B+n+%3C+10%3B+n%2B%2B+)+%0D%0A%09%7B%0D%0A%09%09%2F%2F+use+uniform()+to+transform+a+random+number+%0D%0A%09%09%2F%2F+from+generator+to+a+number+in+N(0%2C1).%0D%0A%09%09std%3A%3Acout+%3C%3C+normal(generator)+%3C%3C+%27+%27%3B%0D%0A%09%7D%0D%0A%09std%3A%3Acout+%3C%3C+std%3A%3Aendl+%3C%3C+std%3A%3Aendl%3B%0D%0A%09%0D%0A++++double+probability+%3D+0.15%3B+%0D%0A%09int+number_of_tests+%3D+100000%3B+%0D%0A%09int+number_of_events+%3D+0%3B+%0D%0A%0D%0A%09std%3A%3Acout+%3C%3C+%22getting+random+events%3A%22+%3C%3C+std%3A%3Aendl%3B+%0D%0A%09for+(int+n+%3D+0%3B+n+%3C+number_of_tests%3B+n%2B%2B)%0D%0A%09%7B%0D%0A%09%09if(+uniform(generator)+%3C%3D+probability+)%0D%0A%09%09%7B+number_of_events%2B%2B%3B+%7D+%0D%0A%09%7D%0D%0A++++%0D%0A%09double+fraction+%3D+(double)+number_of_events+%0D%0A%09%09%2F+(double)+number_of_tests%3B+%0D%0A%09std%3A%3Acout+%3C%3C+%22fraction+of+events%3A+%22+%3C%3C+fraction+%0D%0A%09%09%3C%3C+%22+vs+%22+%3C%3C+probability+%3C%3C+std%3A%3Aendl+%3C%3C+std%3A%3Aendl%3B+%0D%0A%09%0D%0A%09std%3A%3Acout+%3C%3C+%22done!%22+%3C%3C+std%3A%3Aendl%3B+%0D%0A%09return+0%3B%0D%0A%7D%0D%0A

*/