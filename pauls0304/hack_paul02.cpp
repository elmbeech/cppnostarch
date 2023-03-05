#include <iostream>
#include <string>
#include <vector>

void display_vector(std::vector<double>& v) {
    for (int i=0; i < v.size(); i++) { std::cout << i << " : " << v[i] << std::endl; }
    std::cout << std::endl;
}

std::vector<double> operator+(std::vector<double>& v, std::vector<double>& w) {
    unsigned int m = v.size();
    if (w.size() < m) { m = w.size(); }
    std::vector<double> z(m);
    for (unsigned int i=0; i < m; i++) { z[i] = v[i] + w[i]; }
    return z;
}

int main (int argc, char* argv[]) {
    std::cout << "starting program ..." << std::endl;

    // generate a vector of doubles of size 10, initalize with 3.0
    /*
    std::vector<double> v(10, 3.0);
    display_vector(v);
    */

    std::vector<double> v = { 0.0, 1.0, 2.0 }; 
    display_vector(v);

    for (unsigned int i=0; i < v.size(); i++) { v[i] = i; }  // act on element of v
    display_vector(v);
    
    std::vector<double> w = v;  // copy v to w
    for (unsigned int i=0; i < w.size(); i++) { w[i] = i*i; }  // act on element of v
    display_vector(w);

    std::vector<double> z = v + w;  // add v and w using the oepration overload
    display_vector(z);

    z.clear();   // clear vector z
    display_vector(z);

    // play with resize
    /*
    v.resize(3);
    display_vector(v);
    v.resize(12);
    display_vector(v);
    */
    

    // set key as value
    /*
    for (int i=0; i < v.size(); i++) { v[i] = i; }
    display_vector(v);
    */

    // add an element to the vector
    /*
    v.push_back(42.41);
    display_vector(v);
    */

    // trim off 3 last elements of the vector
    /* 
    v.pop_back();
    v.pop_back();
    v.pop_back();
    display_vector(v);
    */

    std::cout << "done!" << std::endl;
    return 0;
} 
