#include <cstddef>
#include <cstdio>

int main() {
    unsigned long maximum = 0;
    unsigned long values[] = {10, 50, 20, 40, 0};
    size_t n_elements = sizeof(values) / sizeof(unsigned long);
    for (size_t i=0; i < n_elements; i++) {
        if (values[i] > maximum) maximum = values[i];
    }
    printf("The maximum values from thsi %ld values is %lu\n", n_elements, maximum);
}
