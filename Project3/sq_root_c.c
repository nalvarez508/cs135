// A signature Nick Alvarez program, produced for Project 3, due September 27, 2018
/* This program will guess the square root of a number using float variables.*/

#include <stdio.h>
#include <math.h>

int main(void)
{
  float n;
  int c = 0;
  printf("Enter a number: ");
  scanf("%f", &n);

  float new_guess, old_guess, middle;
  old_guess = 1.0f;
  //Take input, n, and try to guess the square root
  while ((fabs((new_guess*new_guess)-n)>(1e-5))&&(middle != new_guess))
  {
    new_guess = (old_guess + (n / old_guess)) / 2.0;
    middle = old_guess;
    old_guess = new_guess;
    printf("%d\t%10.5f\n", c, new_guess);
    c++;
  }
  printf("Estimated square root of %.5f: %.5f\n", n, new_guess);
  return 0;
}
