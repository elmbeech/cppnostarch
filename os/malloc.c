#include <stdio.h>

typedef struct _alloc {
    unsigned int size;
    char state;
    struct _alloc* next;
} alloc_t;


int main (void) {
    alloc_t freelist;
    freelist.size = 8;
    freelist.state = 'a';
    freelist.next = NULL;
    printf("hello world! %p\n", (void*)&freelist);
}
