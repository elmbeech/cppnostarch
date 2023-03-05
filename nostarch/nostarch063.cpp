#include <cstdio>

float a {1};
float b {2};
float result1 {a/b};
float result2 (a/b);
//int narrowed_result0 {a/b};  // will not compile
//int narrowed_result1 {(a/b)};  // will not compile
int narrowed_result2 (a/b);

int main() {
    printf("a: %g\n", a);
    printf("b: %g\n", b);
    printf("result1: %g\n", result1);
    printf("result2: %g\n", result2);
    printf("narrowed result2: %d\n", narrowed_result2);
}
