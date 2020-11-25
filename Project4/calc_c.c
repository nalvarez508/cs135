// A signature Nick Alvarez program, produced for Project 4, due October 9, 2018
/* This program will implement a calculator.*/

#include <stdio.h>
#include <math.h>

int o=0;
int i1, i2;
double d1, d2;

int main(void)
{
  printf("This program implements a calculator.\n");
  //This is the main program, which will end only if the user exits.
  while (o!=8)
  {
    //Double calculator
    while (o!=8 && o!=9)
    {
      printf("Options:\n1 - addition\n2 - subtraction\n3 - multiplication\n4 - division\n5 - exp(x)\n6 - log(x)\n7 - toggle calculator type\n8 - exit program\nPlease enter your option: ");
      scanf("%d", &o);
      switch (o)
      {
        //addition
        case 1:
        {
          printf("Enter first term: ");
          scanf("%lf", &d1);
          printf("Enter second term: ");
          scanf("%lf", &d2);
          printf("The sum is: %.15lf\n", d1+d2);
          break;
        }
        //subtraction
        case 2:
        {
          printf("Enter first term: ");
          scanf("%lf", &d1);
          printf("Enter second term: ");
          scanf("%lf", &d2);
          printf("The difference is: %.15lf\n", d1-d2);
          break;
        }
        //multiplication
        case 3:
        {
          printf("Enter first term: ");
          scanf("%lf", &d1);
          printf("Enter second term: ");
          scanf("%lf", &d2);
          printf("The product is: %.15lf\n", d1*d2);
          break;
        }
        //division
        case 4:
        {
          printf("Enter first term: ");
          scanf("%lf", &d1);
          printf("Enter second term: ");
          scanf("%lf", &d2);
          if (d2==0)
          {
            printf("Cannot divide by zero!");
            break;
          }
          else
          {
            printf("The quotient is: %.15lf\n", d1/d2);
            break;
          }
        }
        //exp(x)
        case 5:
        {
          printf("Enter term: ");
          scanf("%lf", &d1);
          printf("The result of exp(%.15lf) is: %.15lf\n", d1, exp(d1));
          break;
        }
        //log(x)
        case 6:
        {
          printf("Enter term: ");
          scanf("%lf", &d1);
          printf("The result of log(%.15lf) is: %.15lf\n", d1, log(d1));
          break;
        }
        //toggle calculator
        case 7:
        {
          printf("Calculator now works with integers.\n");
          o = 9;
          break;
        }
        //exit
        case 8: break;
        default:
        {
          printf("Invalid option.\n");
          o = 0;
          break;
        }
      }
    }

    //Integer calculator
    while (o!=8 && o!=10)
    {
      printf("Options:\n1 - addition\n2 - subtraction\n3 - multiplication\n4 - division\n5 - exp(x)\n6 - log(x)\n7 - toggle calculator type\n8 - exit program\nPlease enter your option: ");
      scanf("%d", &o);
      switch (o)
      {
        //addition
        case 1:
        {
          printf("Enter first term: ");
          scanf("%d", &i1);
          printf("Enter second term: ");
          scanf("%d", &i2);
          printf("The sum is: %d\n", i1+i2);
          break;
        }
        //subtraction
        case 2:
        {
          printf("Enter first term: ");
          scanf("%d", &i1);
          printf("Enter second term: ");
          scanf("%d", &i2);
          printf("The difference is: %d\n", i1-i2);
          break;
        }
        //multiplication
        case 3:
        {
          printf("Enter first term: ");
          scanf("%d", &i1);
          printf("Enter second term: ");
          scanf("%d", &i2);
          printf("The product is: %d\n", i1*i2);
          break;
        }
        //division
        case 4:
        {
          printf("Enter first term: ");
          scanf("%d", &i1);
          printf("Enter second term: ");
          scanf("%d", &i2);
          if (i2==0)
          {
            printf("Cannot divide by zero!");
            break;
          }
          else
          {
            printf("The quotient is: %d\n", i1/i2);
            break;
          }
        }
        //exp(x) or log(x)
        case 5:
        case 6:
        {
          printf("Cannot calculate with integers.\n");
          break;
        }
        //toggle calculator
        case 7:
        {
          printf("Calculator now works with doubles.\n");
          o = 10;
          break;
        }
        //exit
        case 8: break;
        default:
        {
          printf("Invalid option.\n");
          o = 0;
          break;
        }
      }
    }
  }
  return 0;
}
