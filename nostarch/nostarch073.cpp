#include <cstdio>

struct College {
    char name[256];
};

// classes could be overgiven as pointers or objects. pointer is lightweight.   
void print_names(College* ptr_college, size_t n_colleges) {
    for (size_t i = 0; i < n_colleges; i++) {
        printf("%c College\n", ptr_college[i] .name[0]);
        printf("%s College\n", ptr_college[i].name);
        //printf("%s College\n", (*ptr_college).name);
    }
}


int main() {
    // key to the univers
    //int key_to_the_universe[]{3,6,9};
    //int* ptr_key = key_to_the_universe;
    //printf("1st var inside array: %i\n", key_to_the_universe[0]); 
    //printf("array address: %p\n", &key_to_the_universe); 
    //printf("pointer to the array: %p\n", ptr_key); 
    //printf("dereferenced pointer to array: %i\n", *ptr_key); 

    // hogwarts
    College hogwarts[] = {"Hufflepuff","Gryffindor","Ravenclaw", "Slytherin"};
    print_names(hogwarts, sizeof(hogwarts)/sizeof(College));
}

