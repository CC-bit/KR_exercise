#include <stdio.h>

/* Prints Fahrenheit-Celsius table for fahr = 0, 20, ..., 300;
 * floating-point version */
int main() {
  float fahr, celsius, lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;
  fahr = lower;

  printf("Fahrenheit-Celsius table\n\n");
  printf("%3s%6s\n", "F", "C");
  while (fahr <= upper) {
    celsius = (5.0 / 9.0) * (fahr - 32);
    printf("%3.0f%6.1f\n", fahr, celsius);
    fahr += step;
  }
}
