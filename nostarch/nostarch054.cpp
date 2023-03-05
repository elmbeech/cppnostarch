#include <cstdio>

union Variant {
    char string[10];
    int integer;
    double floating_point;
};

int main () {
    Variant v;
    v.integer = 42;
    printf("The ultimate answer: %d\n", v.integer);
    v.floating_point = 2.7182818284;
    printf("Euler's number e: %e\n", v.floating_point);
    printf("A sumpster fire: %d\n", v.integer); 
}

