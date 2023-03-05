#include <cstdio>

struct Taxonomist {
    Taxonomist() {
        printf("(no arguments given)\n");
    }
    Taxonomist(char x) {
        printf("char: %c\n", x);
    }
    Taxonomist(int x) {
        printf("int: %d\n", x);
    }
    Taxonomist(float x) {
        printf("float: %g\n", x);
    }
};

int main() {
    Taxonomist t1;
    Taxonomist t2 {'c'};
    Taxonomist t3 {65537};
    Taxonomist t4 {6.02f};  // why is this f needed
    Taxonomist t5 {6.02e23f};  // why is this f needed
    Taxonomist t6 ('g');
    Taxonomist t7 {'l'};
    Taxonomist t8 {};
    //Taxonomist t9 (); this actually once declares a function
}
