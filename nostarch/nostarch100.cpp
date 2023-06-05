#include <cstdio>

struct Superclass {
    int x;
};

struct Subclass : Superclass {
    int y;
    int foo() {
        return x + y;
    }
};

int main() {
    Subclass sub {5};
    int ich {sub.foo};
    printf('%d', ich);
}

