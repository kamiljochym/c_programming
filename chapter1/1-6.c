#include <ctype.h>
#include <stdio.h>

int main(void) /* count lines in input */
{
  int c, nl, blanks, tabs;

  nl = 0;
  blanks = 0;
  tabs = 0;
  while ((c = getchar()) != EOF) {

    if (c == '\n')
      ++nl;
    if (c == '\t')
      ++tabs;
    if (isspace(c))
      ++blanks;
  }

  printf("%d\n %d\n %d\n", nl, blanks, tabs);
  return 0;
}

