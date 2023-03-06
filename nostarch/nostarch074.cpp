#include <cstdio>

struct College {
    char name[256];
};

// classes could be overgiven as pointers or objects. pointer is lightweight.
void print_name(College* ptr_college) {
    printf("%c College\n", ptr_college->name[0]);
    printf("%c College\n", (*ptr_college).name[0]);
    printf("%s College\n", ptr_college->name);
    printf("%s College\n", (*ptr_college).name); 
}

int main() {
    // key to the univers
    int key_to_the_universe[]{3,6,9};
    int* ptr_key = key_to_the_universe;
    printf("\narray to pointer decay:\n");
    printf("1st var inside array: %i\n", key_to_the_universe[0]); 
    printf("array address: %p\n", &key_to_the_universe); 
    printf("pointer to the array: %p\n", ptr_key); 
    printf("dereferenced pointer to array: %i\n", *ptr_key); 

    // hogwarts direct
    College hogwarts[] = {"Hufflepuff","Gryffindor","Ravenclaw", "Slytherin"};
    College* ptr_college_0 = &hogwarts[0];
    College* ptr_college_1 = &hogwarts[1];
    College* ptr_college_2 = &hogwarts[2];
    College* ptr_college_3 = &hogwarts[3];
    printf("\ndirect:\n");
    print_name(ptr_college_0);
    print_name(ptr_college_1);
    print_name(ptr_college_2);
    print_name(ptr_college_3);

    // pointer arithmetic
    College* ptr_college_0od = hogwarts;  // through array to pointer decay the same as &hogwarts[0]
    College* ptr_college_1st = hogwarts + 1;
    College* ptr_college_2nd = hogwarts + 2;
    College* ptr_college_3rd = hogwarts + 3;
    printf("\npointer arithmetic:\n");
    print_name(ptr_college_0od);
    print_name(ptr_college_1st);
    print_name(ptr_college_2nd);
    print_name(ptr_college_3rd);
}
