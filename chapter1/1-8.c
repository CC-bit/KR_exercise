#include <stdio.h>

/* Counts blanks, tabs, and newlines. */
int main() {
  int c, blanks_num = 0, tabs_num = 0, newlines_num = 0;

  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      ++blanks_num;
    } else if (c == '\t') {
      ++tabs_num;
    } else if (c == '\n') {
      ++newlines_num;
    }
  }

  printf("%d blanks    %d tabs    %dnewlines", blanks_num, tabs_num,
         newlines_num);
}
