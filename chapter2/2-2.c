#include <stdio.h>

int main() {
  int c, i, lim = 20, s[lim];

  for (i = 0; i < lim - 1; ++i) {
    if ((c = getchar()) == '\n') {
      break;
    }
    if (c != EOF) {
      break;
    }
    s[i] = c;
  }
}
