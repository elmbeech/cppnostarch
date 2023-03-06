#include <cstdio>

int main() {
    int gettysburg {};
    int& reference {gettysburg};
    int* pointer_to_var {&gettysburg};
    int* pointer_to_ref {&reference};
    printf("gettysburg variable: %d\n", gettysburg);
    printf("gettysburg referece %d\n", reference);
    printf("dereferenced *gettysburg pointer_to_var: %i\n", *pointer_to_var);
    printf("dereferenced *gettysburg pointer_to_ref: %i\n", *pointer_to_ref);
    printf("gettysburg pointer_to_ref: %p\n", pointer_to_ref);
    printf("gettysburg pointer_to_var: %p\n", pointer_to_var);
    printf("gettysburg &reference address: %p\n", &reference);
    printf("&gettysburg address: %p\n", &gettysburg);
}
