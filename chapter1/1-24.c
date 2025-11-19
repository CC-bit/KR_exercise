#include <stdio.h>

#define NORMAL 0
#define TO_COMMENT 1
#define COMMENT 2
#define TO_NORMAL 3
#define CHAR 4
#define STRING 5
#define CHAR_ESC 6
#define STRING_ESC 7

#define MAX_STACK_SIZE 1000
char stack[MAX_STACK_SIZE];
int cur_index = 0;
void put(int c) {
  if (cur_index >= MAX_STACK_SIZE - 1) {
    printf("Full stack");
    return;
  }
  stack[cur_index + 1] = c;
  ++cur_index;
}
int pop() {
  if (cur_index == 0) {
    printf("Empty stack");
    return 0;
  }
  int item = stack[cur_index];
  stack[cur_index] = 0;
  --cur_index;
  return item;
}

/* Return 1 if it is ( [ { .
 * */
int is_left_pair(int c) { return c == '(' || c == '[' || c == '{'; }
/* Return 1 if it is ) ] } .
 * */
int is_right_pair(int c) { return c == ')' || c == ']' || c == '}'; }
/* Return 1 if pairing success. */
int is_pair(int left, int right) {
  if (left == '(') {
    return right == ')';
  } else if (left == '[') {
    return right == ']';
  } else if (left == '{') {
    return right == '}';
  } else {
    return 0;
  }
}

int state = NORMAL;

void state_machine(int c) {
  if (state == NORMAL) {
    if (c == '/') {
      state = TO_COMMENT;
    } else if (c == '\"') {
      state = STRING;
    } else if (c == '\'') {
      state = CHAR;
    } else if (is_left_pair(c)) {
      put(c);
    } else if (is_right_pair(c)) {
      if (!is_pair(pop(), c)) {
        printf("Syntax error.");
      }
    }
  } else if (state == CHAR) {
    if (c == '\\') {
      state = CHAR_ESC;
    } else if (c == '\'') {
      state = NORMAL;
    }
  } else if (state == STRING) {
    if (c == '\\') {
      state = STRING_ESC;
    } else if (c == '\"') {
      state = NORMAL;
    }
  } else if (state == STRING_ESC) {
    state = STRING;
  } else if (state == CHAR_ESC) {
    state = CHAR;
  } else if (state == TO_COMMENT) {
    if (c == '*') {
      state = COMMENT;
    } else {
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

/* Rrport syntax error when meeting the first error,
 * or report "no error". */
int main() {
  int c;

  while ((c = getchar()) != EOF) {
    state_machine(c);
  }
  if (state != NORMAL || cur_index != 0) {
    printf("Syntax error.");
  } else {
    printf("No error.");
  }
}
