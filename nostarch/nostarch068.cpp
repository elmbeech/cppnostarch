#include <cstdio>

int main() {
    int gettysburg{};
    int* pointer = &gettysburg;
    printf("gettysburg variable: %d\n", gettysburg);
    printf("dereferenced *gettysburg pointer: %i\n", *pointer);
    printf("gettysburg pointer: %p\n", pointer);
    printf("&gettysburg address: %p\n", &gettysburg);
}

