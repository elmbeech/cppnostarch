#include <cstdio>

int main() {
    double an = 6.022'140'9e23;
    long double ann = 6.022'140'9e23;
    printf("Avogadro's Number: %le %lf %lg \n", an, an, an);
    printf("Avogadro's Number: %Le %Lf %Lg \n", ann, ann, ann);

    float hp = 9.75;
    printf("Hogwarts' Platform: %e %f %g \n", hp, hp, hp); 
}
