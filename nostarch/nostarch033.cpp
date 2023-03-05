#include <cstdio>

int main()  {
    unsigned short a = 0b1010'1010;
    printf("%hu\n", a); 

    unsigned int b = 0123;  // this is octal.
    printf("%u\n", b);

    //unsigned long c = 0xFFFF'FFFF'FFFF'FFFF;
    unsigned long c = 0xECE;
    printf("%lu\n", c); 

    unsigned long long d = 0xFFFF'FFFF'FFFF'FFFF;
    printf("%llu\n", d); 

    unsigned int e = 3'669'732'608;
    unsigned int ece = 3'790;
    printf("Yabba %x %x!\n", e, ece);  // hexadecimal representation.

    unsigned int f = 69;
    printf("There are %u,%o leaves here.\n", f, f);
}
