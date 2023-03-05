#include <iostream>
#include <string>
#include <cstdlib>
#include <random>
#include <cstdlib>

int main(int argc,char* argv[]) {
    std::cout << "start program ..." << std::endl;

    // rand 
    //int rand(0.0, 1.0);
    srand(0);  // initialze rand with seed 0
    std::cout << "rand:" << std::endl;
    for (int n=0; n < 10; n++) {
        std::cout << rand() << ' ';
    }
    std::cout << std::endl << std::endl;

    // mersenne twister
    std::mt19937_64 generator(0); // 64bit generator with seed 0

    // uniform dist
    std::uniform_real_distribution<> uniform(0.0, 1.0);
    std::cout << "uniform:" << std::endl;
    for (int n=0; n < 10; n++) {
        std::cout << uniform(generator) << ' ';
    }
    std::cout << std::endl << std::endl;


    // normal dist
    std::normal_distribution<> normal(0.0, 1.0);
    std::cout << "normal:" << std::endl;
    for (int n=0; n < 10; n++) {
        std::cout << normal(generator) << ' ';
    }
    std::cout << std::endl << std::endl;

    // events
    double probability = 0.15;
    int number_of_test = 100000;
    int number_of_event = 0;

    std::cout << "getting random events:" << std::endl;
    for (int n =0; n < number_of_test; n++) {
        if (uniform(generator) <= probability) {  number_of_event++; };
    }

    double fraction = (double) number_of_event / (double) number_of_test;

    std::cout << "fraction of events: " << fraction << " vs " << probability << std::endl << std::endl;

    std::cout << "done!" << std::endl;
    return 0;
}
