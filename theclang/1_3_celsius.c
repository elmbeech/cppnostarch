#include <stdio.h>

/* print fahrengeit celsius tabel */

int main() {
  float fahr;

  #define LOWER  0
  #define UPPER 300
  #define STEP 20

  printf("fahr\tcelsius\n");
  /*for (fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)*/
  for (fahr = UPPER; fahr >= LOWER; fahr = fahr - STEP) {
    printf("%3.1f\t%6.1f\n", fahr, 5.0/9.0 * (fahr - 32.0));
  }
}
