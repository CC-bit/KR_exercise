#include <stdio.h>

#define NORMAL 0
#define TO_COMMENT 1
#define COMMENT 2
#define TO_NORMAL 3
#define CHAR 4
#define STRING 5
#define CHAR_ESC 6
#define STRING_ESC 7

int state = NORMAL;

void state_machine(int c) {
  if (state == NORMAL) {
    if (c == '/') {
      state = TO_COMMENT;
    } else {
      putchar(c);
      if (c == '\"') {
        state = STRING;
      } else if (c == '\'') {
        state = CHAR;
      }
    }
  } else if (state == CHAR) {
    putchar(c);
    if (c == '\\') {
      state = CHAR_ESC;
    } else if (c == '\'') {
      state = NORMAL;
    }
  } else if (state == STRING) {
    putchar(c);
    if (c == '\\') {
      state = STRING_ESC;
    } else if (c == '\"') {
      state = NORMAL;
    }
  } else if (state == STRING_ESC) {
    putchar(c);
    state = STRING;
  } else if (state == CHAR_ESC) {
    putchar(c);
    state = CHAR;
  } else if (state == TO_COMMENT) {
    if (c == '*') {
      state = COMMENT;
    } else {
      putchar('/');
      state = NORMAL;
      state_machine(c);
    }
  } else if (state == COMMENT) {
    if (c == '*') {
      state = TO_NORMAL;
    }
  } else if (state == TO_NORMAL) {
    if (c == '/') {
      state = NORMAL;
    } else if (c != '*') {
      state = COMMENT;
    }
  }
}

int main() {
  int c;

  while ((c = getchar()) != EOF) {
    state_machine(c);
  }
}
