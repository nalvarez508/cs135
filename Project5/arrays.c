// A signature Nick Alvarez program, produced for Project 5, due October 16, 2018
/* This program will count the number of digits in an array then print it. */

#include <stdio.h>

int main(void)
{
  int r,c;
  printf("This program counts occurrences of digits 0 through 9 in an NxM array.\n");
  printf("Enter the size of the array (Row Column): ");
  scanf("%d %d", &r, &c);
  //Todo: Variable length arrays
  const int C=c;
  const int R=r;
  int array[R][C];

  //Asks for user input
  for (r=0; r<R; r++)
  {
    printf("Enter row %d: ", r);
    for (c=0; c<C; c++)
    {
      scanf("%d", &array[r][c]);
    }
  }

  //Counts
  int digits[10]={0};
  int d=0;
  int i=0;
  for (d=0; d<10; d++)
  {
    for (r=0; r<R; r++)
    {
      i=0;
      for (c=0; c<C; c++)
      {
        if (array[r][c]==d)
        {
          i++;
          digits[d]+=i;
        }
      }
    }
  }
  //Total counts
  printf("Total counts for each digit:\n");
  for (d=0; d<10; d++)
  {
    printf("Digit %d occurs %d times\n", d, digits[d]);
  }
  printf("The digit counts directly from the 1D array:\n");
  for (d=0; d<10; d++)
  {
    printf("%d ", digits[d]);
  }

  //Original array
  printf("\nThe original 2D array entered by the user:\n");
  for (r=0; r<R; r++)
  {
    for (c=0; c<C; c++)
    {
      printf("%d ", array[r][c]);
    }
    printf("\n");
  }

  return 0;
}
