#include <stdio.h>

enum hexen {eins, zwei, drei};

int main (void) {
    printf("%c\n", hexen(1));
    return 0;
}
