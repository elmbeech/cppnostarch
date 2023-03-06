#include <cstdio>

int main() {
    int original {100};
    int& ref_original {original};
    printf("Original: %d\n", original);
    printf("Reference: %d\n", ref_original);
    printf("Original addresse: %p\n", &original);
    printf("Reference addresse: %p\n", &ref_original);

    int new_value {200};
    ref_original = new_value;
    printf("Original: %d\n", original);
    printf("New value: %d\n", new_value);
    printf("Reference: %d\n", ref_original);
    printf("Original addresse: %p\n", &original);
    printf("New value addresse: %p\n", &original);
    printf("Reference addresse: %p\n", &ref_original);
}

