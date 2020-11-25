// A signature Nick Alvarez program, produced for Project 7, due November 6, 2018
/* This program will perform arithmetic operations on two complex numbers.*/

#include <stdio.h>

void add(float real_part_1, float imaginary_part_1, float real_part_2, float imaginary_part_2, float* real_result, float* imaginary_result);
void subtract(float real_part_1, float imaginary_part_1, float real_part_2, float imaginary_part_2, float* real_result, float* imaginary_result);
void multiply(float real_part_1, float imaginary_part_1, float real_part_2, float imaginary_part_2, float* real_result, float* imaginary_result);
void divide(float real_part_1, float imaginary_part_1, float real_part_2, float imaginary_part_2, float* real_result, float* imaginary_result);
void read_num(float *real_part, float *imaginary_part);
void read_nums(float* real_part_1, float* imaginary_part_1, float* real_part_2, float* imaginary_part_2);
void print_complex(float real_part, float imaginary_part);

int main()
{
  int userInput=0;
  float real_part_1, imaginary_part_1, real_part_2, imaginary_part_2, real_result, imaginary_result;
  printf("Complex Number Arithmetic Program:\n");
  while(userInput!=5)
  {
    printf("1) Add two complex numbers\n2) Subtract two complex numbers\n3) Mulitply two complex numbers\n4) Divide two complex numbers\n5) Quit\n");
    printf("Choose an option (1 - 5): ");
    scanf("%d", &userInput);

    switch (userInput)
    {
      case 1:
      {
        add(real_part_1, imaginary_part_1, real_part_2, imaginary_part_2, &real_result, &imaginary_result);
        print_complex(real_result, imaginary_result);
        break;
      }
      case 2:
      {
        subtract(real_part_1, imaginary_part_1, real_part_2, imaginary_part_2, &real_result, &imaginary_result);
        print_complex(real_result, imaginary_result);
        break;
      }
      case 3:
      {
        multiply(real_part_1, imaginary_part_1, real_part_2, imaginary_part_2, &real_result, &imaginary_result);
        print_complex(real_result, imaginary_result);
        break;
      }
      case 4:
      {
        divide(real_part_1, imaginary_part_1, real_part_2, imaginary_part_2, &real_result, &imaginary_result);
        print_complex(real_result, imaginary_result);
      }
      case 5:
      {
        printf("Bye!\n");
        break;
      }
      default:
      {
        printf("Please input a valid menu option\n");
        break;
      }
    }
  }
  return 0;
}

//Adds two complex numbers together, splitting real and imagniary parts
void add(float real_part_1, float imaginary_part_1, float real_part_2, float imaginary_part_2, float* real_result, float* imaginary_result)
{
  read_nums(&real_part_1, &imaginary_part_1, &real_part_2, &imaginary_part_2);
  *real_result=real_part_1+real_part_2;
  *imaginary_result=imaginary_part_1+imaginary_part_2;
}

//Subtracts two complex numbers, splitting real and imaginary parts
void subtract(float real_part_1, float imaginary_part_1, float real_part_2, float imaginary_part_2, float* real_result, float* imaginary_result)
{
  read_nums(&real_part_1, &imaginary_part_1, &real_part_2, &imaginary_part_2);
  *real_result=real_part_1-real_part_2;
  *imaginary_result=imaginary_part_1-imaginary_part_2;
}

//Multiplies two complex numbers by foiling real and imaginary parts
void multiply(float real_part_1, float imaginary_part_1, float real_part_2, float imaginary_part_2, float* real_result, float* imaginary_result)
{
  read_nums(&real_part_1, &imaginary_part_1, &real_part_2, &imaginary_part_2);
  *real_result=real_part_1*real_part_2-imaginary_part_1*imaginary_part_2;
  *imaginary_result=real_part_1*imaginary_part_2+real_part_2*imaginary_part_1;
}

//Divides two complex numbers by foiling the first with the second conjugate, then the second with the second conjugate
void divide(float real_part_1, float imaginary_part_1, float real_part_2, float imaginary_part_2, float* real_result, float* imaginary_result)
{
  read_nums(&real_part_1, &imaginary_part_1, &real_part_2, &imaginary_part_2);
  *real_result=(real_part_1*real_part_2+imaginary_part_1*imaginary_part_2)/(real_part_2*real_part_2+imaginary_part_2*imaginary_part_2);
  *imaginary_result=(real_part_1*-imaginary_part_2+imaginary_part_1*real_part_2)/(real_part_2*real_part_2+imaginary_part_2*imaginary_part_2);
}

//Gathers user input
void read_num(float *real_part, float *imaginary_part)
{
  printf("Please type in the real component: ");
  scanf("%f", &(*real_part));
  printf("Please type in the imaginary component: ");
  scanf("%f", &(*imaginary_part));
}

//Informs user which complex number is being called
void read_nums(float* real_part_1, float* imaginary_part_1, float* real_part_2, float* imaginary_part_2)
{
  printf("Reading the first imaginary number...\n");
  read_num(real_part_1, imaginary_part_1);
  printf("Reading the second imaginary number...\n");
  read_num(real_part_2, imaginary_part_2);
}

//Prints the result
void print_complex(float real_part, float imaginary_part)
{
  printf("The operation yields %6.3f + %6.3fi\n", real_part, imaginary_part);
}
