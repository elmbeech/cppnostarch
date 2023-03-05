#include <stdio.h>

/* print Fahrenheit Celsius table for fahr = 0, 20, ... 300 */

int main() {
  float fahr, celsius;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  printf("faren\tcelsi\n");
  fahr = lower;
  while (fahr <= upper) {
    /*celsius = 5 * (fahr - 32) / 9;   *//* 5/9 would be truncated to 0 because it is int */
    celsius = 5.0/9.0 * (fahr - 32.0);
    printf("%3.0f\t%3.1f\n", fahr, celsius);
    fahr = fahr + step;
  }
}

