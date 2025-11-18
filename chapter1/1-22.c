#include <stdio.h>

#define LINE_LENGTH 10
#define FOLD_POINT LINE_LENGTH - 1
#define TAB_STOP 8

int pos = 0, blanks = 0;

void forward() {
  ++pos;
  if (pos >= FOLD_POINT) {
    putchar('\n');
    pos = blanks = 0;
  }
}

int main() {
  int c;

  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      ++blanks;
      forward();
    } else if (c == '\n') {
      putchar('\n');
      pos = blanks = 0;
    } else {
      for (int i = 0; i < blanks; ++i) {
        putchar(' ');
      }
      blanks = 0;

      putchar(c);
      forward();
    }
  }
}
