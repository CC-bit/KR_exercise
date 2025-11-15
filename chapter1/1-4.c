#include <stdio.h>

/* Prints Celsius-Fahrenheit table for celsius = -20, 0, ..., 160;
 * floating-point version */
int main() {
  float fahr, celsius, lower, upper, step;

  lower = -20;
  upper = 160;
  step = 20;
  celsius = lower;

  printf("Celsius-Fahrenheit table\n\n");
  printf("%6s%6s\n", "C", "F");
  printf("------------\n");

  while (celsius <= upper) {
    fahr = (9.0 / 5.0) * celsius + 32;
    printf("%6.0f%6.1f\n", celsius, fahr);
    celsius += step;
  }
}
