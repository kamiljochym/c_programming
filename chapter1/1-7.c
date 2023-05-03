#include <ctype.h>
#include <stdio.h>
/* Exercise 1-7. Write a program to copy its input to its output, replacing each
 * string of one or more blanks by a single blank. */
int main(void) {
  int c;
  int blankCount = 0;
  char input[255];
  while ((c = getchar()) != EOF) {

    /* outputLine[i] = c; */
    if (isspace(c)) {
      putchar(c);

      while (isspace(c)) {
        c = getchar();
      }
    }
    putchar(c);
  }

  return 0;
}
