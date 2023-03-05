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
    printf("1st var inside array: %i\n", key_to_the_universe[0]); 
    printf("array address: %p\n", &key_to_the_universe); 
    printf("pointer to the array: %p\n", ptr_key); 
    printf("dereferenced pointer to array: %i\n", *ptr_key); 

    // hogwarts
    College hogwarts[] = {"Hufflepuff","Gryffindor","Ravenclaw", "Slytherin"};
    College* ptr_college_0od = &hogwarts[0];
    College* ptr_college_1st = &hogwarts[1];
    College* ptr_college_2nd = &hogwarts[2];
    College* ptr_college_3rd = &hogwarts[3];
    print_name(ptr_college_0od);
    print_name(ptr_college_1st);
    print_name(ptr_college_2nd);
    print_name(ptr_college_3rd);
}

