#include <stdio.h>

#define LENGTH_P1 0
#define LENGTH_P1_P2 1
#define LENGTH_P2_P3 2
#define LENGTH_P3 3
#define POINT1 4
#define POINT2 8
#define POINT3 12

/* Prints a histogram of the lengths of words in its input. */
int main() {
  int c, count, lengths[4];

  count = 0;
  for (int i = 0; i < 4; ++i) {
    lengths[i] = 0;
  }

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t' || c == '\n') {
      if (count >= 0 && count < POINT1) {
        ++lengths[LENGTH_P1];
      } else if (count >= POINT1 && count < POINT2) {
        ++lengths[LENGTH_P1_P2];
      } else if (count >= POINT2 && count < POINT3) {
        ++lengths[LENGTH_P2_P3];
      } else {
        ++lengths[LENGTH_P3];
      }
      count = 0;
    } else {
      ++count;
    }
  }

  int p1 = lengths[LENGTH_P1];
  printf(" 0|\n");
  printf("  |");
  for (int i = 0; i < p1; ++i) {
    printf("#");
  }
  printf(" %d\n", p1);

  int p2 = lengths[LENGTH_P1_P2];
  printf(" 4|\n");
  printf("  |");
  for (int i = 0; i < p2; ++i) {
    printf("#");
  }
  printf(" %d\n", p2);

  int p3 = lengths[LENGTH_P2_P3];
  printf(" 8|\n");
  printf("  |");
  for (int i = 0; i < p3; ++i) {
    printf("#");
  }
  printf(" %d\n", p3);

  int p4 = lengths[LENGTH_P3];
  printf("12|\n");
  printf("  |");
  for (int i = 0; i < p4; ++i) {
    printf("#");
  }
  printf(" %d\n", p4);
}
