#include <stdio.h>

int c = 37;

void swap(int *pa, int *pb) {
    int t = *pa;
    *pa = *pb;
    *pb = t;
    //printf("swap: a = %d, b = %d\n", a, b);
    //printf("swap: c = %d\n", c);
    return;
}

int main(void) {
    int a = 21;
    int b = 17;

    //printf("swap: c = %d\n", c);

    swap(&a, &b);
    printf("main: a = %d, b = %d\n", a, b);
    return 0;
}
