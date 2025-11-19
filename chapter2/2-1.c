#include <limits.h>
#include <stdio.h>

int main() {
  char c[] = "char";
  char s[] = "short";
  char i[] = "int";
  char l[] = "long";

  printf("The range of unsigned %s is: 0 ~ %u\n", c, UCHAR_MAX);
  printf("The range of signed %s is: %d ~ %u\n", c, SCHAR_MIN, SCHAR_MAX);

  printf("The range of unsigned %s is: 0 ~ %d\n", s, USHRT_MAX);
  printf("The range of %s is: %d ~ %d\n", s, SHRT_MIN, SHRT_MAX);

  printf("The range of unsigned %s is: 0 ~ %u\n", i, UINT_MAX);
  printf("The range of %s is: %d ~ %d\n", i, INT_MIN, INT_MAX);

  printf("The range of unsigned %s is: 0 ~ %lu\n", l, ULONG_MAX);
  printf("The range of %s is: %d ~ %ld\n", l, LONG_MIN, LONG_MAX);
}
