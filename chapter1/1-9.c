#include <stdio.h>

/* Copies its input to output, ignoring more than one blanks. */
int main() {
  int c, blanks_count = 0;

  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      if (blanks_count == 0) {
        putchar(c);
      }
      ++blanks_count;
    } else {
      putchar(c);
      blanks_count = 0;
    }
  }
}
