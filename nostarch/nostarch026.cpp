#include <cstdio>
#include "step_function.h"

int main() {
    int num1 = 42;
    int result1 = stepfun::step_function(num1);

    int num2 = 0;
    int result2 = stepfun::step_function(num2);

    int num3 = -32767;
    int result3 = stepfun::step_function(num3);

    printf("num1: %d, step: %d\n", num1, result1);
    printf("num2: %d, step: %d\n", num2, result2);
    printf("num3: %d, step: %d\n", num3, result3);

    return 0;
}

