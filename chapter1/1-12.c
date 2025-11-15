#include <complex.h>
#include <stdio.h>

/* Copies its input to output, one word per line. */
int main() {
  int c, state;

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      putchar('\n');
    } else {
      putchar(c);
    }
  }
}
