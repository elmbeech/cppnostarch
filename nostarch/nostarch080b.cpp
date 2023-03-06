#include <cstdio>

int main() {
    int original {100};
    int* ptr_original {&original};
    printf("Original: %d\n", original);
    printf("Original address: %p\n", &original);
    printf("Pointer address: %p\n", ptr_original);
    printf("Derefernced pointer: %i\n", *ptr_original);

    int new_value {200};
    ptr_original = &new_value;
    printf("Original: %d\n", original);
    printf("New value: %d\n", new_value);
    printf("Original address: %p\n", &original);
    printf("New value address: %p\n", &new_value);
    printf("Pointer address: %p\n", ptr_original);
    printf("Derefernced pointer: %i\n", *ptr_original);
}

