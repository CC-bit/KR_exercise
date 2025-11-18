#include <stdio.h>

#define TAB_STOP 8

int dist_to_tab = TAB_STOP; // it will be 4, 3, 2, 1, 4, 3, ...
int blanks_num = 0;

void minus_dist() {
  if (dist_to_tab == 1) {
    dist_to_tab = TAB_STOP;
  } else {
    --dist_to_tab;
  }
}

void replace_with_tab() {
  // putchar('\t');
  putchar('t');
  dist_to_tab = TAB_STOP;
  blanks_num = 0;
}

int main() {
  int c;

  while (1) {
    c = getchar();
    if (c == ' ') {
      if (dist_to_tab == 1) {
        replace_with_tab();
      } else {
        ++blanks_num;
        minus_dist();
      }
    } else if (c == '\t') {
      replace_with_tab();
    } else {
      for (int i = 0; i < blanks_num; ++i) {
        // putchar(' ');
        putchar('b');
      }
      if (c != EOF) {
        putchar(c);
        minus_dist();
      }
      blanks_num = 0;
    }

    if (c == EOF) {
      return 0;
    }
  }
}
