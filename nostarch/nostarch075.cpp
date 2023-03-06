#include <cstdio>

int main() {
    char lower[] {"abc?e"};
    char upper[] {"ABC?E"};
    char* ptr_upper {upper};  //Equivalent: &upper[0]

    lower[3] = 'd';      // lower now contains a b c d e \0
    ptr_upper[3] = 'D';  // upper now contains A B C D E \0
    
    printf("lower: %s\nupper: %s\n", lower, upper);

    //lower[7] = 'g';  // super bad. You must never do this!
    printf("lower overflow: %c%c%c\n", lower[7], lower[8], lower[9]);
    printf("upper overflow: %c%c%c\n", upper[7], upper[8], upper[9]);
}

