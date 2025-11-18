#include <stdio.h>

#define TAB_STOP 4;

int main() {
  int c, dist_to_tab;
  dist_to_tab = TAB_STOP; // it will be 4, 3, 2, 1, 4, 3, ...

  while ((c = getchar()) != EOF) {
    if (c == '\t') {
      for (int i = 0; i < dist_to_tab; ++i) {
        putchar(' ');
      }
      dist_to_tab = TAB_STOP;
    } else {
      putchar(c);
      if (c == '\n') {
        dist_to_tab = TAB_STOP;
      } else if (dist_to_tab == 1) {
        dist_to_tab = TAB_STOP;
      } else {
        --dist_to_tab;
      }
    }
  }
  return 0;
}
