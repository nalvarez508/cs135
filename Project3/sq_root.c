// A signature Nick Alvarez program, produced for Project 3, due September 27, 2018
/* This program will guess the square root of a number using double variables.*/

#include <stdio.h>
#include <math.h>

int main(void)
{
  double n;
  printf("Enter a number: ");
  scanf("%lf", &n);

  double new_guess, old_guess;
  old_guess = 1.0;
  //Take input, n, and try to guess the square root
  while (fabs((new_guess*new_guess)-n)>(1e-5))
  {
    new_guess = (old_guess + (n / old_guess)) / 2.0;
    old_guess = new_guess;
    printf("%10.5lf\n", new_guess);
  }
  printf("Estimated square root of %.5lf: %.5lf\n", n, new_guess);
  return 0;
}
