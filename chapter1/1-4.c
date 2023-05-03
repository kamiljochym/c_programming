
#include <stdio.h>

/* print Fahrenheit-Celsius table
for f = 0, 20, ..., 300 */

main() {
  int lower, upper, step;
  float fahr, celsius;
  lower = 0;   /* lower limit of temperature table */
  upper = 300; /* upper limit */
  step = 20;   /* step size */
  fahr = lower;

  printf("Celsius to Farenheit Conversion Table\n");
  while (celsius <= upper) {
    /* celsius = (5.0 / 9.0) * (fahr - 32.0); */
    fahr = celsius / (5.0 / 9.0) + 32.0;
    printf("%4.0f %6.1f\n", celsius, fahr);
    celsius = celsius + step;
  }
}
